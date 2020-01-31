



import java.io.*;
import java.util.*;
import javax.tools.StandardLocation;
import com.sun.tools.javac.code.Flags;
import com.sun.tools.javac.code.Kinds;
import com.sun.tools.javac.code.Scope;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.Type.ClassType;
import com.sun.tools.javac.code.TypeTag;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.jvm.ClassReader;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Names;

public class T6889255 {
    boolean testInterfaces = true;
    boolean testSyntheticMethods = true;

    
    enum GenericKind {
        NOT_GENERIC,
        GENERIC
    };

    enum ClassKind {
        CLASS("Clss"),
        INTERFACE("Intf"),
        ENUM("Enum");
        final String base;
        ClassKind(String base) { this.base = base; }
    };

    enum NestedKind {
        
        NONE,
        
        NESTED,
        
        INNER,
        
        INIT_LOCAL,
        
        INIT_ANON,
        
        METHOD_LOCAL,
        
        METHOD_ANON
    };

    enum MethodKind {
        ABSTRACT,
        CONSTRUCTOR,
        METHOD,
        STATIC_METHOD,
        BRIDGE_METHOD
    };

    enum FinalKind {
        
        NO_FINAL,
        
        USE_FINAL
    };

    public static void main(String... args) throws Exception {
        new T6889255().run();
    }

    void run() throws Exception {
        genTest();

        test("no-args", false);
        test("g",       true,  "-g");

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    
    void genTest() throws Exception {
        BufferedWriter out = new BufferedWriter(new FileWriter("Test.java"));

        
        
        out.write("interface Base {\n");
        out.write("    Object base_m1(int i1);\n");
        out.write("    Object base_m2(int i1);\n");
        out.write("}\n");

        int outerNum = 0;
        
        for (GenericKind outerGenericKind: GenericKind.values()) {
            for (ClassKind outerClassKind: ClassKind.values()) {
                if (outerGenericKind == GenericKind.GENERIC && outerClassKind == ClassKind.ENUM)
                    continue;
                String outerClassName = outerClassKind.base + (outerNum++);
                String outerTypeArg = outerClassKind.toString().charAt(0) + "T";
                if (outerClassKind == ClassKind.CLASS)
                    out.write("abstract ");
                out.write(outerClassKind.toString().toLowerCase() + " " + outerClassName);
                if (outerGenericKind == GenericKind.GENERIC)
                    out.write("<" + outerTypeArg + ">");
                if (outerClassKind == ClassKind.INTERFACE)
                    out.write(" extends Base");
                else
                    out.write(" implements Base");
                out.write(" {\n");
                if (outerClassKind == ClassKind.ENUM) {
                    out.write("    E1(0,0,0), E2(0,0,0), E3(0,0,0);\n");
                    out.write("    " + outerClassName + "(int i1, int i2, int i3) { }\n");
                }
                
                int nestedNum = 0;
                int methodNum = 0;
                for (GenericKind nestedGenericKind: GenericKind.values()) {
                    nextNestedKind:
                    for (NestedKind nestedKind: NestedKind.values()) {
                        
                        
                        if (nestedKind == NestedKind.NONE && nestedGenericKind != GenericKind.NOT_GENERIC)
                            continue;
                        if ((nestedKind == NestedKind.METHOD_ANON || nestedKind == NestedKind.INIT_ANON)
                                && nestedGenericKind == GenericKind.GENERIC)
                            continue;
                        String indent = "    ";
                        boolean haveFinal = false;
                        switch (nestedKind) {
                            case METHOD_ANON: case METHOD_LOCAL:
                                if (outerClassKind == ClassKind.INTERFACE)
                                    continue nextNestedKind;
                                out.write(indent + "void m" +  + (nestedNum++) + "() {\n");
                                indent += "    ";
                                out.write(indent + "final int fi1 = 0;\n");
                                haveFinal = true;
                                break;
                            case INIT_ANON: case INIT_LOCAL:
                                if (outerClassKind == ClassKind.INTERFACE)
                                    continue nextNestedKind;
                                out.write(indent + "{\n");
                                indent += "    ";
                                break;
                        }
                        for (ClassKind nestedClassKind: ClassKind.values()) {
                            if ((nestedGenericKind == GenericKind.GENERIC)
                                    && (nestedClassKind == ClassKind.ENUM))
                                continue;
                            if ((nestedKind == NestedKind.METHOD_ANON || nestedKind == NestedKind.METHOD_LOCAL
                                    || nestedKind == NestedKind.INIT_ANON || nestedKind == NestedKind.INIT_LOCAL)
                                    && nestedClassKind != ClassKind.CLASS)
                                continue;
                            
                            
                            if (nestedKind == NestedKind.NONE && nestedClassKind != ClassKind.CLASS)
                                continue;

                            ClassKind methodClassKind;
                            String methodClassName;
                            boolean allowAbstractMethods;
                            boolean allowStaticMethods;
                            switch (nestedKind) {
                                case NONE:
                                    methodClassKind = outerClassKind;
                                    methodClassName = outerClassName;
                                    allowAbstractMethods = (outerClassKind == ClassKind.CLASS);
                                    allowStaticMethods = (outerClassKind != ClassKind.INTERFACE);
                                    break;
                                case METHOD_ANON:
                                case INIT_ANON:
                                    out.write(indent + "new Base() {\n");
                                    indent += "    ";
                                    methodClassKind = ClassKind.CLASS;
                                    methodClassName = null;
                                    allowAbstractMethods = false;
                                    allowStaticMethods = false;
                                    break;
                                default: { 
                                    String nestedClassName = "N" + nestedClassKind.base + (nestedNum++);
                                    String nestedTypeArg = nestedClassKind.toString().charAt(0) + "T";
                                    out.write(indent);
                                    if (nestedKind == NestedKind.NESTED)
                                        out.write("static ");
                                    if (nestedClassKind == ClassKind.CLASS)
                                        out.write("abstract ");
                                    out.write(nestedClassKind.toString().toLowerCase() + " " + nestedClassName);
                                    if (nestedGenericKind == GenericKind.GENERIC)
                                        out.write("<" + nestedTypeArg + ">");
                                    if (nestedClassKind == ClassKind.INTERFACE)
                                        out.write(" extends Base ");
                                    else
                                        out.write(" implements Base ");
                                    out.write(" {\n");
                                    indent += "    ";
                                    if (nestedClassKind == ClassKind.ENUM) {
                                        out.write(indent + "E1(0,0,0), E2(0,0,0), E3(0,0,0);\n");
                                        out.write(indent + nestedClassName + "(int i1, int i2, int i3) { }\n");
                                    }
                                    methodClassKind = nestedClassKind;
                                    methodClassName = nestedClassName;
                                    allowAbstractMethods = (nestedClassKind == ClassKind.CLASS);
                                    allowStaticMethods = (nestedKind == NestedKind.NESTED && nestedClassKind != ClassKind.INTERFACE);
                                    break;
                                }
                            }

                            
                            for (GenericKind methodGenericKind: GenericKind.values()) {
                                for (FinalKind finalKind: FinalKind.values()) {
                                    for (MethodKind methodKind: MethodKind.values()) {









                                        switch (methodKind) {
                                            case CONSTRUCTOR:
                                                if (nestedKind == NestedKind.METHOD_ANON || nestedKind == NestedKind.INIT_ANON)
                                                    break;
                                                if (methodClassKind != ClassKind.CLASS)
                                                    break;
                                                if (finalKind == FinalKind.USE_FINAL && !haveFinal)
                                                    break;
                                                out.write(indent);
                                                if (methodGenericKind == GenericKind.GENERIC) {
                                                    out.write("<CT> " + methodClassName + "(CT c1, CT c2");
                                                } else {
                                                    out.write(methodClassName + "(boolean b1, char c2");
                                                }
                                                if (finalKind == FinalKind.USE_FINAL) {
                                                    
                                                    out.write(", int i3) { int i = fi1; }\n");
                                                } else
                                                    out.write(") { }\n");
                                                break;
                                            case ABSTRACT:
                                                if (!allowAbstractMethods)
                                                    continue;
                                                
                                            case METHOD:
                                                if (finalKind == FinalKind.USE_FINAL && !haveFinal)
                                                    break;
                                                out.write(indent);
                                                if (methodKind == MethodKind.ABSTRACT)
                                                    out.write("abstract ");
                                                if (methodGenericKind == GenericKind.GENERIC)
                                                    out.write("<MT> ");
                                                out.write("void m" + (methodNum++) + "(int i1, long l2, float f3)");
                                                if (methodKind == MethodKind.ABSTRACT || methodClassKind == ClassKind.INTERFACE)
                                                    out.write(";\n");
                                                else {
                                                    out.write(" {");
                                                    if (finalKind == FinalKind.USE_FINAL)
                                                        out.write(" int i = fi1;");
                                                    out.write(" }\n");
                                                }
                                                break;
                                            case BRIDGE_METHOD:
                                                if (methodGenericKind == GenericKind.GENERIC)
                                                    break;
                                                out.write(indent);
                                                
                                                
                                                
                                                String methodName = (finalKind == FinalKind.NO_FINAL ? "base_m1" : "base_m2");
                                                out.write("public String " + methodName + "(int i1)");
                                                if (methodClassKind == ClassKind.INTERFACE)
                                                    out.write(";\n");
                                                else {
                                                    out.write(" {");
                                                    if (finalKind == FinalKind.USE_FINAL && haveFinal)
                                                        out.write(" int i = fi1;");
                                                    out.write(" return null; }\n");
                                                }
                                                break;
                                            case STATIC_METHOD:
                                                if (!allowStaticMethods)
                                                    break;
                                                if (finalKind == FinalKind.USE_FINAL && !haveFinal)
                                                    break;
                                                out.write(indent + "static ");
                                                if (methodGenericKind == GenericKind.GENERIC)
                                                    out.write("<MT> ");
                                                out.write("void m" + (methodNum++) + "(int i1, long l2, float f3) {");
                                                if (finalKind == FinalKind.USE_FINAL)
                                                    out.write(" int i = fi1;");
                                                out.write(" }\n");
                                                break;
                                        }

                                    }
                                }
                            }
                            if (nestedKind != NestedKind.NONE) {
                                indent = indent.substring(0, indent.length() - 4);
                                out.write(indent + "};\n");
                            }
                        }
                        switch (nestedKind) {
                            case METHOD_ANON: case METHOD_LOCAL:
                            case INIT_ANON: case INIT_LOCAL:
                                indent = indent.substring(0, indent.length() - 4);
                                out.write(indent + "}\n\n");
                        }
                    }
                }
                out.write("}\n\n");
            }
        }
        out.close();
    }


    void test(String testName, boolean expectNames, String... opts) throws Exception {
        System.err.println("Test " + testName
                + ": expectNames:" + expectNames
                + " javacOpts:" + Arrays.asList(opts));

        File outDir = new File(testName);
        outDir.mkdirs();
        compile(outDir, opts);

        Context ctx = new Context();
        JavacFileManager fm = new JavacFileManager(ctx, true, null);
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(outDir));
        ClassReader cr = ClassReader.instance(ctx);
        cr.saveParameterNames = true;
        Names names = Names.instance(ctx);

        Set<String> classes = getTopLevelClasses(outDir);
        Deque<String> work = new LinkedList<String>(classes);
        String classname;
        while ((classname = work.poll()) != null) {
            System.err.println("Checking class " + classname);
            ClassSymbol sym = cr.enterClass(names.table.fromString(classname));
            sym.complete();

            if ((sym.flags() & Flags.INTERFACE) != 0 && !testInterfaces)
                continue;

            for (Scope.Entry e = sym.members_field.elems; e != null; e = e.sibling) {
                System.err.println("Checking member " + e.sym);
                switch (e.sym.kind) {
                    case Kinds.TYP: {
                        String name = e.sym.flatName().toString();
                        if (!classes.contains(name)) {
                            classes.add(name);
                            work.add(name);
                        }
                        break;
                    }
                    case Kinds.MTH:
                        verify((MethodSymbol) e.sym, expectNames);
                        break;
                }

            }
        }
    }

    void verify(MethodSymbol m, boolean expectNames) {
        if ((m.flags() & Flags.SYNTHETIC) != 0 && !testSyntheticMethods)
            return;

        
        int i = 1;
        for (VarSymbol v: m.params()) {
            String expectName;
            if (expectNames)
                expectName = getExpectedName(v, i);
            else
                expectName = "arg" + (i - 1);
            checkEqual(expectName, v.name.toString());
            i++;
        }
    }

    String getExpectedName(VarSymbol v, int i) {
        
        
        if (((v.owner.owner.flags() & Flags.ENUM) != 0)
                && v.owner.name.toString().equals("valueOf"))
            return "name";
        
        
        if ((v.owner.owner.flags() & Flags.INTERFACE) != 0)
            return "arg" + (i - 1);
        
        
        if ((v.owner.flags() & Flags.ABSTRACT) != 0)
            return "arg" + (i - 1);
        
        if ((v.owner.flags() & Flags.BRIDGE) != 0)
            return "arg" + (i - 1);

        
        Type t = v.type;
        String s;
        if (t.hasTag(TypeTag.CLASS))
            s = ((ClassType) t).tsym.name.toString();
        else
            s = t.toString();
        return String.valueOf(Character.toLowerCase(s.charAt(0))) + i;
    }

    void compile(File outDir, String... opts) throws Exception {
        
        List<String> args = new ArrayList<String>();
        args.add("-d");
        args.add(outDir.getPath());
        args.addAll(Arrays.asList(opts));
        
        args.add("Test.java");
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.close();
        if (rc != 0) {
            System.err.println(sw.toString());
            throw new Exception("compilation failed unexpectedly");
        }
    }

    Set<String> getTopLevelClasses(File outDir) {
        Set<String> classes = new HashSet<String>();
        for (String f: outDir.list()) {
            if (f.endsWith(".class") && !f.contains("$"))
                classes.add(f.replace(".class", ""));
        }
        return classes;
    }

    void checkEqual(String expect, String found) {
        if (!expect.equals(found))
            error("mismatch: expected:" + expect + " found:" + found);
    }

    void error(String msg) {
        System.err.println(msg);
        errors++;
        throw new Error();
    }

    int errors;
}
