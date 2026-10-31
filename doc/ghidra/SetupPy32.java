// Pre-analysis: add the memory map the raw dump lacks, then seed both vector tables.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;

public class SetupPy32 extends GhidraScript {

    private void block(String name, long addr, long size) throws Exception {
        MemoryBlock b = currentProgram.getMemory()
            .createUninitializedBlock(name, toAddr(addr), size, false);
        b.setRead(true); b.setWrite(true); b.setExecute(false);
        println(String.format("block %-10s 0x%08x +0x%x", name, addr, size));
    }

    private int seedVectors(long base, String tag) throws Exception {
        int made = 0;
        for (int i = 0; i < 48; i++) {
            Address slot = toAddr(base + 4L * i);
            long v = Integer.toUnsignedLong(getInt(slot));
            if ((v & 1L) == 0) continue;                 // Thumb entries only
            long t = v & ~1L;
            if (t < 0x08000000L || t > 0x0801FFFFL) continue;
            Address target = toAddr(t);
            disassemble(target);
            if (getFunctionAt(target) == null) {
                createFunction(target, null);
                made++;
            }
        }
        println(tag + " vector table at 0x" + Long.toHexString(base) + ": " + made + " entry points");
        return made;
    }

    private void enableAggressiveFinder() {
        // Non-default analyzer: finds code that recursive descent never reaches.
        for (String name : getCurrentAnalysisOptionsAndValues(currentProgram).keySet()) {
            if (name.toLowerCase().contains("aggressive")) {
                setAnalysisOption(currentProgram, name, "true");
                println("enabled analyzer option: " + name);
            }
        }
    }

    @Override
    public void run() throws Exception {
        enableAggressiveFinder();
        block("SRAM",     0x20000000L, 0x4000);
        block("PERIPH",   0x40000000L, 0x30000);
        block("IOPORT",   0x50000000L, 0x2000);
        seedVectors(0x08000000L, "bootloader");
        seedVectors(0x08002800L, "application");
    }
}
