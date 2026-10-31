// Resolve literal-pool peripheral pointers: label every peripheral base, then
// type each aligned flash word that points into peripheral space as a pointer.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.*;

public class LabelPeriph extends GhidraScript {
    @Override
    public void run() throws Exception {
        String table = getScriptArgs()[0];
        TreeMap<Long, String> bases = new TreeMap<>();
        try (BufferedReader r = new BufferedReader(new FileReader(table))) {
            String line;
            while ((line = r.readLine()) != null) {
                String[] p = line.trim().split("\\s+");
                if (p.length == 2) bases.put(Long.decode(p[1]), p[0]);
            }
        }
        // Name each peripheral base inside the PERIPH / IOPORT blocks.
        int labelled = 0;
        for (Map.Entry<Long, String> e : bases.entrySet()) {
            Address a = toAddr(e.getKey());
            MemoryBlock b = currentProgram.getMemory().getBlock(a);
            if (b == null) continue;
            createLabel(a, e.getValue(), true, SourceType.USER_DEFINED);
            labelled++;
        }
        println("peripheral bases labelled: " + labelled);

        // Type literal-pool words that hold a peripheral address.
        MemoryBlock flash = currentProgram.getMemory().getBlock(toAddr(0x08000000L));
        long start = flash.getStart().getOffset(), end = flash.getEnd().getOffset();
        int typed = 0;
        Map<String, Integer> hits = new TreeMap<>();
        for (long off = start; off + 4 <= end; off += 4) {
            Address at = toAddr(off);
            long v = Integer.toUnsignedLong(getInt(at));
            if (v < 0x40000000L || v > 0x50002000L) continue;
            Map.Entry<Long, String> e = bases.floorEntry(v);
            if (e == null || v - e.getKey() >= 0x400) continue;
            if (getInstructionAt(at) != null) continue;      // don't clobber code
            try {
                clearListing(at, toAddr(off + 3));
                createData(at, PointerDataType.dataType);
                typed++;
                hits.merge(e.getValue(), 1, Integer::sum);
            } catch (Exception ignored) { }
        }
        println("literal-pool peripheral pointers typed: " + typed);
        for (Map.Entry<String, Integer> h : hits.entrySet())
            println(String.format("  %-10s %d", h.getKey(), h.getValue()));
    }
}
