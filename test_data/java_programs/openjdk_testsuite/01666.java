






import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import javax.lang.model.element.Element;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.Highlighter;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticListener;
import javax.tools.JavaFileObject;

import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskListener;
import com.sun.tools.javac.code.Symbol;
import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.tree.EndPosTable;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCCompilationUnit;
import com.sun.tools.javac.tree.JCTree.JCImport;
import com.sun.tools.javac.tree.TreeInfo;
import com.sun.tools.javac.tree.TreeScanner;
import com.sun.tools.javac.util.Pair;

import static com.sun.tools.javac.tree.JCTree.Tag.*;



public class CheckAttributedTree extends JavacTestingAbstractThreadedTest {
    
    public static void main(String... args) throws Exception {
        String testSrc = System.getProperty("test.src");
        File baseDir = (testSrc == null) ? null : new File(testSrc);
        throwAssertionOnError = false;
        boolean ok = new CheckAttributedTree().run(baseDir, args);
        if (!ok) {
            if (testSrc != null)  
                throw new Error("failed");
            else
                System.exit(1);
        }
    }

    
    boolean run(File baseDir, String... args) throws Exception {
        if (args.length == 0) {
            usage(System.out);
            return true;
        }

        List<File> files = new ArrayList<File>();
        for (int i = 0; i < args.length; i++) {
            String arg = args[i];
            if (arg.equals("-encoding") && i + 1 < args.length)
                encoding = args[++i];
            else if (arg.equals("-gui"))
                gui = true;
            else if (arg.equals("-q"))
                quiet = true;
            else if (arg.equals("-v")) {
                verbose = true;
                printAll = true;
            }
            else if (arg.equals("-t") && i + 1 < args.length)
                tags.add(args[++i]);
            else if (arg.equals("-ef") && i + 1 < args.length)
                excludeFiles.add(new File(baseDir, args[++i]));
            else if (arg.equals("-et") && i + 1 < args.length)
                excludeTags.add(args[++i]);
            else if (arg.equals("-r")) {
                if (excludeFiles.size() > 0)
                    throw new Error("-r must be used before -ef");
                File d = baseDir;
                while (!new File(d, "TEST.ROOT").exists()) {
                    if (d == null)
                        throw new Error("cannot find TEST.ROOT");
                    d = d.getParentFile();
                }
                baseDir = d;
            }
            else if (arg.startsWith("-"))
                throw new Error("unknown option: " + arg);
            else {
                while (i < args.length)
                    files.add(new File(baseDir, args[i++]));
            }
        }

        for (File file: files) {
            if (file.exists())
                test(file);
            else
                error("File not found: " + file);
        }

        if (fileCount.get() != 1)
            errWriter.println(fileCount + " files read");
        checkAfterExec(false);

        return (gui || errCount.get() == 0);
    }

    
    void usage(PrintStream out) {
        out.println("Usage:");
        out.println("  java CheckAttributedTree options... files...");
        out.println("");
        out.println("where options include:");
        out.println("-q        Quiet: don't report on inapplicable files");
        out.println("-gui      Display returns in a GUI viewer");
        out.println("-v        Verbose: report on files as they are being read");
        out.println("-t tag    Limit checks to tree nodes with this tag");
        out.println("          Can be repeated if desired");
        out.println("-ef file  Exclude file or directory");
        out.println("-et tag   Exclude tree nodes with given tag name");
        out.println("");
        out.println("files may be directories or files");
        out.println("directories will be scanned recursively");
        out.println("non java files, or java files which cannot be parsed, will be ignored");
        out.println("");
    }

    
    void test(final File file) {
        if (excludeFiles.contains(file)) {
            if (!quiet)
                error("File " + file + " excluded");
            return;
        }

        if (file.isDirectory()) {
            for (File f: file.listFiles()) {
                test(f);
            }
            return;
        }

        if (file.isFile() && file.getName().endsWith(".java")) {
            pool.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        if (verbose)
                            errWriter.println(file);
                        fileCount.incrementAndGet();
                        NPETester p = new NPETester();
                        p.test(read(file));
                    } catch (AttributionException e) {
                        if (!quiet) {
                            error("Error attributing " + file + "\n" + e.getMessage());
                        }
                    } catch (IOException e) {
                        error("Error reading " + file + ": " + e);
                    }
                }
            });
        }

        if (!quiet)
            error("File " + file + " ignored");
    }

    
    StringWriter sw = new StringWriter();
    PrintWriter pw = new PrintWriter(sw);
    Reporter r = new Reporter(pw);

    
    List<Pair<JCCompilationUnit, JCTree>> read(File file) throws IOException, AttributionException {
        r.errors = 0;
        Iterable<? extends JavaFileObject> files = fm.get().getJavaFileObjects(file);
        String[] opts = { "-XDshouldStopPolicy=ATTR", "-XDverboseCompilePolicy" };
        JavacTask task = (JavacTask)comp.getTask(pw, fm.get(), r, Arrays.asList(opts), null, files);
        final List<Element> analyzedElems = new ArrayList<>();
        task.setTaskListener(new TaskListener() {
            public void started(TaskEvent e) {
                if (e.getKind() == TaskEvent.Kind.ANALYZE)
                        analyzedElems.add(e.getTypeElement());
            }
            public void finished(TaskEvent e) { }
        });

        try {
            Iterable<? extends CompilationUnitTree> trees = task.parse();
            task.analyze();
            List<Pair<JCCompilationUnit, JCTree>> res = new ArrayList<>();
            
            for (CompilationUnitTree t : trees) {
               JCCompilationUnit cu = (JCCompilationUnit)t;
               for (JCTree def : cu.defs) {
                   if (def.hasTag(CLASSDEF) &&
                           analyzedElems.contains(((JCTree.JCClassDecl)def).sym)) {
                       
                       res.add(new Pair<>(cu, def));
                   }
               }
            }
            return res;
        }
        catch (Throwable t) {
            throw new AttributionException("Exception while attributing file: " + file);
        }
    }

    
    void error(String msg) {
        System.err.println(msg);
        errCount.incrementAndGet();
    }

    
    boolean quiet;
    
    boolean gui;
    
    Viewer viewer;
    
    boolean verbose;
    
    String encoding;
    
    Set<String> tags = new HashSet<String>();
    
    Set<File> excludeFiles = new HashSet<File>();
    
    Set<String> excludeTags = new HashSet<String>();
    
    TreeUtil treeUtil = new TreeUtil();

    
    private class NPETester extends TreeScanner {
        void test(List<Pair<JCCompilationUnit, JCTree>> trees) {
            for (Pair<JCCompilationUnit, JCTree> p : trees) {
                sourcefile = p.fst.sourcefile;
                endPosTable = p.fst.endPositions;
                encl = new Info(p.snd, endPosTable);
                p.snd.accept(this);
            }
        }

        @Override
        public void scan(JCTree tree) {
            if (tree == null ||
                    excludeTags.contains(treeUtil.nameFromTag(tree.getTag()))) {
                return;
            }

            Info self = new Info(tree, endPosTable);
            if (mandatoryType(tree)) {
                check(tree.type != null,
                        "'null' field 'type' found in tree ", self);
                if (tree.type==null)
                    new Throwable().printStackTrace();
            }

            Field errField = checkFields(tree);
            if (errField!=null) {
                check(false,
                        "'null' field '" + errField.getName() + "' found in tree ", self);
            }

            Info prevEncl = encl;
            encl = self;
            tree.accept(this);
            encl = prevEncl;
        }

        private boolean mandatoryType(JCTree that) {
            return that instanceof JCTree.JCExpression ||
                    that.hasTag(VARDEF) ||
                    that.hasTag(METHODDEF) ||
                    that.hasTag(CLASSDEF);
        }

        private final List<String> excludedFields = Arrays.asList("varargsElement", "targetType");

        void check(boolean ok, String label, Info self) {
            if (!ok) {
                if (gui) {
                    if (viewer == null)
                        viewer = new Viewer();
                    viewer.addEntry(sourcefile, label, encl, self);
                }
                error(label + self.toString() + " encl: " + encl.toString() +
                        " in file: " + sourcefile + "  " + self.tree);
            }
        }

        Field checkFields(JCTree t) {
            List<Field> fieldsToCheck = treeUtil.getFieldsOfType(t,
                    excludedFields,
                    Symbol.class,
                    Type.class);
            for (Field f : fieldsToCheck) {
                try {
                    if (f.get(t) == null) {
                        return f;
                    }
                }
                catch (IllegalAccessException e) {
                    System.err.println("Cannot read field: " + f);
                    
                }
            }
            return null;
        }

        @Override
        public void visitImport(JCImport tree) { }

        @Override
        public void visitTopLevel(JCCompilationUnit tree) {
            scan(tree.defs);
        }

        JavaFileObject sourcefile;
        EndPosTable endPosTable;
        Info encl;
    }

    
    private class Info {
        Info() {
            tree = null;
            tag = ERRONEOUS;
            start = 0;
            pos = 0;
            end = Integer.MAX_VALUE;
        }

        Info(JCTree tree, EndPosTable endPosTable) {
            this.tree = tree;
            tag = tree.getTag();
            start = TreeInfo.getStartPos(tree);
            pos = tree.pos;
            end = TreeInfo.getEndPos(tree, endPosTable);
        }

        @Override
        public String toString() {
            return treeUtil.nameFromTag(tree.getTag()) + "[start:" + start + ",pos:" + pos + ",end:" + end + "]";
        }

        final JCTree tree;
        final JCTree.Tag tag;
        final int start;
        final int pos;
        final int end;
    }

    
    private static class TreeUtil {
        String nameFromTag(JCTree.Tag tag) {
            String name = tag.name();
            return (name == null) ? "??" : name;
        }

        List<Field> getFieldsOfType(JCTree t, List<String> excludeNames, Class<?>... types) {
            List<Field> buf = new ArrayList<Field>();
            for (Field f : t.getClass().getDeclaredFields()) {
                if (!excludeNames.contains(f.getName())) {
                    for (Class<?> type : types) {
                        if (type.isAssignableFrom(f.getType())) {
                            f.setAccessible(true);
                            buf.add(f);
                            break;
                        }
                    }
                }
            }
            return buf;
        }
    }

    
    private static class ParseException extends Exception {
        ParseException(String msg) {
            super(msg);
        }
    }

    private static class AttributionException extends Exception {
        AttributionException(String msg) {
            super(msg);
        }
    }

    
    private static class Reporter implements DiagnosticListener<JavaFileObject> {
        Reporter(PrintWriter out) {
            this.out = out;
        }

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            
            switch (diagnostic.getKind()) {
                case ERROR:
                    errors++;
            }
        }
        int errors;
        PrintWriter out;
    }

    
    private class Viewer extends JFrame {
        
        Viewer() {
            initGUI();
        }

        
        void addEntry(JavaFileObject file, String check, Info encl, Info self) {
            Entry e = new Entry(file, check, encl, self);
            DefaultComboBoxModel m = (DefaultComboBoxModel) entries.getModel();
            m.addElement(e);
            if (m.getSize() == 1)
                entries.setSelectedItem(e);
        }

        
        private void initGUI() {
            JPanel head = new JPanel(new GridBagLayout());
            GridBagConstraints lc = new GridBagConstraints();
            GridBagConstraints fc = new GridBagConstraints();
            fc.anchor = GridBagConstraints.WEST;
            fc.fill = GridBagConstraints.HORIZONTAL;
            fc.gridwidth = GridBagConstraints.REMAINDER;

            entries = new JComboBox();
            entries.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    showEntry((Entry) entries.getSelectedItem());
                }
            });
            fc.insets.bottom = 10;
            head.add(entries, fc);
            fc.insets.bottom = 0;
            head.add(new JLabel("check:"), lc);
            head.add(checkField = createTextField(80), fc);
            fc.fill = GridBagConstraints.NONE;
            head.add(setBackground(new JLabel("encl:"), enclColor), lc);
            head.add(enclPanel = new InfoPanel(), fc);
            head.add(setBackground(new JLabel("self:"), selfColor), lc);
            head.add(selfPanel = new InfoPanel(), fc);
            add(head, BorderLayout.NORTH);

            body = new JTextArea();
            body.setFont(Font.decode(Font.MONOSPACED));
            body.addCaretListener(new CaretListener() {
                public void caretUpdate(CaretEvent e) {
                    int dot = e.getDot();
                    int mark = e.getMark();
                    if (dot == mark)
                        statusText.setText("dot: " + dot);
                    else
                        statusText.setText("dot: " + dot + ", mark:" + mark);
                }
            });
            JScrollPane p = new JScrollPane(body,
                    JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                    JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
            p.setPreferredSize(new Dimension(640, 480));
            add(p, BorderLayout.CENTER);

            statusText = createTextField(80);
            add(statusText, BorderLayout.SOUTH);

            pack();
            setLocationRelativeTo(null); 
            setVisible(true);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }

        
        private void showEntry(Entry e) {
            try {
                
                setTitle(e.file.getName());
                checkField.setText(e.check);
                enclPanel.setInfo(e.encl);
                selfPanel.setInfo(e.self);
                
                body.setText(e.file.getCharContent(true).toString());
                Highlighter highlighter = body.getHighlighter();
                highlighter.removeAllHighlights();
                addHighlight(highlighter, e.encl, enclColor);
                addHighlight(highlighter, e.self, selfColor);
                scroll(body, getMinPos(enclPanel.info, selfPanel.info));
            } catch (IOException ex) {
                body.setText("Cannot read " + e.file.getName() + ": " + e);
            }
        }

        
        private JTextField createTextField(int width) {
            JTextField f = new JTextField(width);
            f.setEditable(false);
            f.setBorder(null);
            return f;
        }

        
        private void addHighlight(Highlighter h, Info info, Color c) {
            int start = info.start;
            int end = info.end;
            if (start == -1 && end == -1)
                return;
            if (start == -1)
                start = end;
            if (end == -1)
                end = start;
            try {
                h.addHighlight(info.start, info.end,
                        new DefaultHighlighter.DefaultHighlightPainter(c));
                if (info.pos != -1) {
                    Color c2 = new Color(c.getRed(), c.getGreen(), c.getBlue(), (int)(.4f * 255)); 
                    h.addHighlight(info.pos, info.pos + 1,
                        new DefaultHighlighter.DefaultHighlightPainter(c2));
                }
            } catch (BadLocationException e) {
                e.printStackTrace();
            }
        }

        
        private int getMinPos(Info... values) {
            int i = Integer.MAX_VALUE;
            for (Info info: values) {
                if (info.start >= 0) i = Math.min(i, info.start);
                if (info.pos   >= 0) i = Math.min(i, info.pos);
                if (info.end   >= 0) i = Math.min(i, info.end);
            }
            return (i == Integer.MAX_VALUE) ? 0 : i;
        }

        
        private JComponent setBackground(JComponent comp, Color c) {
            comp.setOpaque(true);
            comp.setBackground(c);
            return comp;
        }

        
        private void scroll(final JTextArea t, final int pos) {
            
            
            
            EventQueue.invokeLater(new Runnable() {
                public void run() {
                    try {
                        Rectangle r = t.modelToView(pos);
                        JScrollPane p = (JScrollPane) SwingUtilities.getAncestorOfClass(JScrollPane.class, t);
                        r.y = Math.max(0, r.y - p.getHeight() * 2 / 5);
                        r.height += p.getHeight() * 4 / 5;
                        t.scrollRectToVisible(r);
                    } catch (BadLocationException ignore) {
                    }
                }
            });
        }

        private JComboBox entries;
        private JTextField checkField;
        private InfoPanel enclPanel;
        private InfoPanel selfPanel;
        private JTextArea body;
        private JTextField statusText;

        private Color selfColor = new Color(0.f, 1.f, 0.f, 0.2f); 
        private Color enclColor = new Color(1.f, 0.f, 0.f, 0.2f); 

        
        private class InfoPanel extends JPanel {
            InfoPanel() {
                add(tagName = createTextField(20));
                add(new JLabel("start:"));
                add(addListener(start = createTextField(6)));
                add(new JLabel("pos:"));
                add(addListener(pos = createTextField(6)));
                add(new JLabel("end:"));
                add(addListener(end = createTextField(6)));
            }

            void setInfo(Info info) {
                this.info = info;
                tagName.setText(treeUtil.nameFromTag(info.tag));
                start.setText(String.valueOf(info.start));
                pos.setText(String.valueOf(info.pos));
                end.setText(String.valueOf(info.end));
            }

            JTextField addListener(final JTextField f) {
                f.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        body.setCaretPosition(Integer.valueOf(f.getText()));
                        body.getCaret().setVisible(true);
                    }
                });
                return f;
            }

            Info info;
            JTextField tagName;
            JTextField start;
            JTextField pos;
            JTextField end;
        }

        
        private class Entry {
            Entry(JavaFileObject file, String check, Info encl, Info self) {
                this.file = file;
                this.check = check;
                this.encl = encl;
                this.self= self;
            }

            @Override
            public String toString() {
                return file.getName() + " " + check + " " + getMinPos(encl, self);
            }

            final JavaFileObject file;
            final String check;
            final Info encl;
            final Info self;
        }
    }

    
    static AtomicInteger fileCount = new AtomicInteger();

}
