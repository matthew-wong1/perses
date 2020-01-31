

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
import java.lang.reflect.Modifier;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
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
import javax.tools.StandardJavaFileManager;

import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.code.Flags;
import com.sun.tools.javac.tree.EndPosTable;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCAnnotatedType;
import com.sun.tools.javac.tree.JCTree.JCCompilationUnit;
import com.sun.tools.javac.tree.JCTree.JCNewClass;
import com.sun.tools.javac.tree.JCTree.JCVariableDecl;
import com.sun.tools.javac.tree.TreeInfo;
import com.sun.tools.javac.tree.TreeScanner;

import static com.sun.tools.javac.tree.JCTree.Tag.*;
import static com.sun.tools.javac.util.Position.NOPOS;




public class TreePosTest {
    
    public static void main(String... args) {
        String testSrc = System.getProperty("test.src");
        File baseDir = (testSrc == null) ? null : new File(testSrc);
        boolean ok = new TreePosTest().run(baseDir, args);
        if (!ok) {
            if (testSrc != null)  
                throw new Error("failed");
            else
                System.exit(1);
        }
    }

    
    boolean run(File baseDir, String... args) {
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
            else if (arg.equals("-v"))
                verbose = true;
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
                    d = d.getParentFile();
                    if (d == null)
                        throw new Error("cannot find TEST.ROOT");
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

        if (fileCount != 1)
            System.err.println(fileCount + " files read");
        if (errors > 0)
            System.err.println(errors + " errors");

        return (gui || errors == 0);
    }

    
    void usage(PrintStream out) {
        out.println("Usage:");
        out.println("  java TreePosTest options... files...");
        out.println("");
        out.println("where options include:");
        out.println("-gui      Display returns in a GUI viewer");
        out.println("-q        Quiet: don't report on inapplicable files");
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

    
    void test(File file) {
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
            try {
                if (verbose)
                    System.err.println(file);
                fileCount++;
                PosTester p = new PosTester();
                p.test(read(file));
            } catch (ParseException e) {
                if (!quiet) {
                    error("Error parsing " + file + "\n" + e.getMessage());
                }
            } catch (IOException e) {
                error("Error reading " + file + ": " + e);
            }
            return;
        }

        if (!quiet)
            error("File " + file + " ignored");
    }

    
    StringWriter sw = new StringWriter();
    PrintWriter pw = new PrintWriter(sw);
    Reporter r = new Reporter(pw);
    JavacTool tool = JavacTool.create();
    StandardJavaFileManager fm = tool.getStandardFileManager(r, null, null);

    
    JCCompilationUnit read(File file) throws IOException, ParseException {
        JavacTool tool = JavacTool.create();
        r.errors = 0;
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(file);
        JavacTask task = tool.getTask(pw, fm, r, Collections.<String>emptyList(), null, files);
        Iterable<? extends CompilationUnitTree> trees = task.parse();
        pw.flush();
        if (r.errors > 0)
            throw new ParseException(sw.toString());
        Iterator<? extends CompilationUnitTree> iter = trees.iterator();
        if (!iter.hasNext())
            throw new Error("no trees found");
        JCCompilationUnit t = (JCCompilationUnit) iter.next();
        if (iter.hasNext())
            throw new Error("too many trees found");
        return t;
    }

    
    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    
    private static String getTagName(JCTree.Tag tag) {
        String name = tag.name();
        return (name == null) ? "??" : name;
    }

    
    int fileCount;
    
    int errors;
    
    boolean quiet;
    
    boolean verbose;
    
    boolean gui;
    
    String encoding;
    
    Viewer viewer;
    
    Set<String> tags = new HashSet<String>();
    
    Set<File> excludeFiles = new HashSet<File>();
    
    Set<String> excludeTags = new HashSet<String>();

    
    private class PosTester extends TreeScanner {
        void test(JCCompilationUnit tree) {
            sourcefile = tree.sourcefile;
            endPosTable = tree.endPositions;
            encl = new Info();
            tree.accept(this);
        }

        @Override
        public void scan(JCTree tree) {
            if (tree == null)
                return;

            Info self = new Info(tree, endPosTable);
            if (check(encl, self)) {
                
                
                
                
                if ((self.tag == MODIFIERS || self.tag == BLOCK)
                        && self.pos == NOPOS) {
                    
                    check("start == NOPOS", encl, self, self.start == NOPOS);
                    check("end == NOPOS", encl, self, self.end == NOPOS);
                } else {
                    
                    check("start != NOPOS", encl, self, self.start != NOPOS);
                    check("pos != NOPOS", encl, self, self.pos != NOPOS);
                    check("end != NOPOS", encl, self, self.end != NOPOS);
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    check("encl.start <= start", encl, self, encl.start <= self.start);
                    check("start <= pos", encl, self, self.start <= self.pos);
                    if (!( (self.tag == TYPEARRAY ||
                            isAnnotatedArray(self.tree))
                            && (encl.tag == VARDEF ||
                                encl.tag == METHODDEF ||
                                encl.tag == TYPEARRAY ||
                                isAnnotatedArray(encl.tree))
                           ||
                            encl.tag == ANNOTATED_TYPE && self.tag == SELECT
                         )) {
                        check("encl.pos <= start || end <= encl.pos",
                                encl, self, encl.pos <= self.start || self.end <= encl.pos);
                    }
                    check("pos <= end", encl, self, self.pos <= self.end);
                    if (!( (self.tag == TYPEARRAY || isAnnotatedArray(self.tree)) &&
                            (encl.tag == TYPEARRAY || isAnnotatedArray(encl.tree))
                           ||
                            encl.tag == MODIFIERS && self.tag == ANNOTATION
                         ) ) {
                        check("end <= encl.end", encl, self, self.end <= encl.end);
                    }
                }
            }

            Info prevEncl = encl;
            encl = self;
            tree.accept(this);
            encl = prevEncl;
        }

        private boolean isAnnotatedArray(JCTree tree) {
            return tree.hasTag(ANNOTATED_TYPE) &&
                            ((JCAnnotatedType)tree).underlyingType.hasTag(TYPEARRAY);
        }

        @Override
        public void visitVarDef(JCVariableDecl tree) {
            
            
            
            
            if ((tree.mods.flags & Flags.ENUM) != 0) {
                scan(tree.mods);
                if (tree.init != null) {
                    if (tree.init.hasTag(NEWCLASS)) {
                        JCNewClass init = (JCNewClass) tree.init;
                        if (init.args != null && init.args.nonEmpty()) {
                            scan(init.args);
                        }
                        if (init.def != null && init.def.defs != null) {
                            scan(init.def.defs);
                        }
                    }
                }
            } else
                super.visitVarDef(tree);
        }

        boolean check(Info encl, Info self) {
            if (excludeTags.size() > 0) {
                if (encl != null && excludeTags.contains(getTagName(encl.tag))
                        || excludeTags.contains(getTagName(self.tag)))
                    return false;
            }
            return tags.size() == 0 || tags.contains(getTagName(self.tag));
        }

        void check(String label, Info encl, Info self, boolean ok) {
            if (!ok) {
                if (gui) {
                    if (viewer == null)
                        viewer = new Viewer();
                    viewer.addEntry(sourcefile, label, encl, self);
                }

                String s = "encl: " + encl.tree.toString() +
                        "  this: " + self.tree.toString();
                String msg = sourcefile.getName() + ": " + label + ": " +
                        "encl:" + encl + " this:" + self + "\n" +
                        s.substring(0, Math.min(80, s.length())).replaceAll("[\r\n]+", " ");
                error(msg);
            }
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
            return getTagName(tree.getTag()) + "[start:" + start + ",pos:" + pos + ",end:" + end + "]";
        }

        final JCTree tree;
        final JCTree.Tag tag;
        final int start;
        final int pos;
        final int end;
    }

    
    private static class ParseException extends Exception {
        ParseException(String msg) {
            super(msg);
        }
    }

    
    private static class Reporter implements DiagnosticListener<JavaFileObject> {
        Reporter(PrintWriter out) {
            this.out = out;
        }

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            out.println(diagnostic);
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
                tagName.setText(getTagName(info.tag));
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
}

