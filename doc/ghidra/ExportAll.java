// Post-analysis: dump a function map and the full decompilation.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Reference;
import java.io.*;
import java.util.*;

public class ExportAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/ghidra_out";
        DecompInterface d = new DecompInterface();
        DecompileOptions o = new DecompileOptions();
        d.setOptions(o);
        d.openProgram(currentProgram);

        PrintWriter c   = new PrintWriter(new BufferedWriter(new FileWriter(out + "/ghidra_decompiled.c")));
        PrintWriter map = new PrintWriter(new BufferedWriter(new FileWriter(out + "/ghidra_function_map.txt")));
        map.printf("%-12s %-34s %7s %6s %s%n", "Address", "Name", "Bytes", "Xrefs", "CallsOut");
        map.println("-------------------------------------------------------------------------------");

        int n = 0, ok = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        List<Function> fns = new ArrayList<>();
        while (it.hasNext()) fns.add(it.next());

        for (Function f : fns) {
            n++;
            Address a = f.getEntryPoint();
            int xrefs = 0;
            for (Reference r : getReferencesTo(a)) xrefs++;
            map.printf("%-12s %-34s %7d %6d %d%n", a.toString(), f.getName(),
                       f.getBody().getNumAddresses(), xrefs, f.getCalledFunctions(monitor).size());

            DecompileResults res = d.decompileFunction(f, 90, monitor);
            c.println("// ==== " + a + "  " + f.getName()
                      + "  (" + f.getBody().getNumAddresses() + " bytes, " + xrefs + " xrefs)");
            if (res != null && res.decompileCompleted()) {
                c.println(res.getDecompiledFunction().getC());
                ok++;
            } else {
                c.println("// DECOMPILATION FAILED: " + (res == null ? "null" : res.getErrorMessage()));
            }
            c.println();
            if (n % 100 == 0) println("decompiled " + n + "/" + fns.size());
        }
        c.close(); map.close(); d.dispose();
        println("FUNCTIONS=" + n + " DECOMPILED_OK=" + ok);
    }
}
