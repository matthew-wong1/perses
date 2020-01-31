



import java.util.Collection;
import java.util.List;
import java.util.ArrayList;
import java.util.concurrent.TimeoutException;
import java.io.*;
import java.sql.SQLException;
import java.sql.SQLTransientException;

public class LambdaTest2_SAM2 {
    private static List<String> strs = new ArrayList<String>();

    public static void main(String[] args) {
        strs.add("copy");
        strs.add("paste");
        strs.add("delete");
        strs.add("rename");

        LambdaTest2_SAM2 test = new LambdaTest2_SAM2();

        
        test.methodAB((List list) -> 100);

        
        test.methodFGHI((String s) -> new Integer(22));
        
        test.methodJK((String s) -> new ArrayList<Number>());
        test.methodJK((String s) -> new ArrayList());
        
        test.methodJL((String s) -> new ArrayList<Number>());
        test.methodJL((String s) -> new ArrayList());
        
        test.methodJKL((String s) -> new ArrayList<Number>());
        test.methodJKL((String s) -> new ArrayList());
        
        test.methodJKLM((String s) -> new ArrayList<Number>());
        test.methodJKLM((String s) -> new ArrayList());

        
        test.methodNO((File f) -> {
                String temp = null;
                StringBuffer sb = new StringBuffer();
                try
                {
                    BufferedReader br = new BufferedReader(new FileReader(f));
                    while((temp=br.readLine()) != null)
                        sb.append(temp).append("\n");
                }
                catch(FileNotFoundException fne){throw fne;}
                catch(IOException e){e.printStackTrace();}
                return sb.toString();
        });
        
        test.methodNOP((File f) -> {
                String temp = null;
                StringBuffer sb = new StringBuffer();
                try
                {
                    BufferedReader br = new BufferedReader(new FileReader(f));
                    while((temp=br.readLine()) != null)
                        sb.append(temp).append("\n");
                }
                catch(IOException e){e.printStackTrace();}
                return sb.toString();
        });
        
        test.methodBooDoo((String s) -> s.length());

        
        test.methodQR((Iterable i) -> new ArrayList<String>());
        test.methodQR((Iterable i) -> new ArrayList());
        
        test.methodUV((List<String> list) -> {
                test.exceptionMethod1();
                test.exceptionMethod2();
                return new ArrayList<String>();
        });
        test.methodUV((List<String> list) -> {
                test.exceptionMethod1();
                test.exceptionMethod2();
                return new ArrayList();
        });
        
        test.methodUVW((List list) -> {
                test.exceptionMethod1();
                test.exceptionMethod2();
                return new ArrayList<String>();
        });
        test.methodUVW((List list) -> {
                test.exceptionMethod1();
                test.exceptionMethod2();
                return new ArrayList();
        });
    }

    private void exceptionMethod1() throws EOFException{
    }

    private void exceptionMethod2() throws SQLTransientException{
    }

    
    void methodAB (AB ab) {
        System.out.println("methodAB(): SAM type interface AB object instantiated: " + ab);
        System.out.println(ab.getOldest(strs));
    }

    
    void methodFGHI(FGHI f) {
        System.out.println("methodFGHI(): SAM type interface FGHI object instantiated: " + f);
        System.out.println(f.getValue("str"));
    }

    
    void methodJK(JK jk) {
        System.out.println("methodJK(): SAM type interface JK object instantiated: " + jk);
        for(Number n : jk.getAll("in"))
            System.out.println(n);
    }

    
    void methodJL(JL jl) {
        System.out.println("methodJL(): SAM type interface JL object instantiated: " + jl);
        for(Number n : ((J)jl).getAll("in")) 
            System.out.println(n);
    }

    
    void methodJKL(JKL jkl) { 
        System.out.println("methodJKL(): SAM type interface JKL object instantiated: " + jkl);
        for(Number n : ((J)jkl).getAll("in"))
            System.out.println(n);
    }

    
    void methodJKLM(JKLM jklm) { 
        System.out.println("methodJKLM(): SAM type interface JKLM object instantiated: " + jklm);
        for(Number n : ((J)jklm).getAll("in"))
            System.out.println(n);
    }

    
    void methodNO(NO no) {
        System.out.println("methodNO(): SAM type interface \"NO\" object instantiated: " + no);
        try {
            System.out.println("text=" + no.getText(new File("a.txt")));
            System.out.println("got here, no exception thrown");
        }
        catch(FileNotFoundException e){e.printStackTrace();}
    }

    
    void methodNOP(NOP nop) {
        System.out.println("methodNOP(): SAM type interface \"NOP\" object instantiated: " + nop);
        System.out.println("text=" + nop.getText(new File("a.txt")));
    }

    
    void methodBooDoo(BooDoo bd) {
        System.out.println("methodBooDoo(): SAM type interface BooDoo object instantiated: " + bd);
        System.out.println("result=" + bd.getAge("lambda"));
    }

    
    void methodQR(QR qr) {
        System.out.println("methodQR(): SAM type interface QR object instantiated: " + qr);
        System.out.println("Iterable returned: " + qr.m(new SQLException()));
    }

    
    void methodUV(UV uv) {
        System.out.println("methodUV(): SAM type interface UV object instantiated: " + uv);
        try{
            System.out.println("result returned: " + uv.foo(strs));
        }catch(EOFException e){
            System.out.println(e.getMessage());
        }catch(SQLTransientException ex){
            System.out.println(ex.getMessage());
        }
    }

    
    void methodUVW(UVW uvw) {
        System.out.println("methodUVW(): SAM type interface UVW object instantiated: " + uvw);
        try{
            System.out.println("passing List<String>: " + uvw.foo(strs));
            System.out.println("passing List: " + uvw.foo(new ArrayList()));
        }catch(EOFException e){
            System.out.println(e.getMessage());
        }catch(SQLTransientException ex){
            System.out.println(ex.getMessage());
        }
    }
}
