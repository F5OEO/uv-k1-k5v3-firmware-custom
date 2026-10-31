// Close the recursive-descent coverage gap: create a function at every Thumb
// "push {..,lr}" prologue sitting in space no function claims, then re-analyse
// so Ghidra follows the direct calls those functions make. Repeat until stable.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;

public class SeedPrologues extends GhidraScript {

    private static final long FLASH_LO = 0x08000000L, FLASH_HI = 0x0801FFFFL;

    private long coveredBytes() {
        long n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            n += f.getBody().getNumAddresses();
        return n;
    }

    @Override
    public void run() throws Exception {
        println("before: functions=" + currentProgram.getFunctionManager().getFunctionCount()
                + " covered=" + coveredBytes() + " B");

        int total = 0;
        for (int round = 1; round <= 8; round++) {
            int made = 0, rejected = 0;
            for (long a = FLASH_LO; a + 2 <= FLASH_HI; a += 2) {
                Address at = toAddr(a);
                MemoryBlock b = currentProgram.getMemory().getBlock(at);
                if (b == null || !b.isInitialized()) continue;
                if (getFunctionContaining(at) != null) continue;   // already claimed

                int w = getShort(at) & 0xFFFF;
                if ((w & 0xFF00) != 0xB500) continue;              // push {..., lr} only

                try {
                    // The Aggressive Instruction Finder may already have turned these
                    // bytes into code without creating a function; promote those too.
                    if (getInstructionAt(at) == null) disassemble(at);
                    if (getInstructionAt(at) == null) { rejected++; continue; }
                    Function f = createFunction(at, null);
                    if (f == null) { rejected++; continue; }
                    made++;
                } catch (Exception e) {
                    rejected++;
                }
            }
            total += made;
            println("round " + round + ": +" + made + " functions (" + rejected + " rejected)");
            if (made == 0) break;
            analyzeChanges(currentProgram);   // let Ghidra follow their direct calls
        }

        println("after:  functions=" + currentProgram.getFunctionManager().getFunctionCount()
                + " covered=" + coveredBytes() + " B  (seeded " + total + ")");
    }
}
