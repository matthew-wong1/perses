
import java.util.ArrayList;

class T8065986a {
    T8065986a() {
        super(new Object<>());
    }

    T8065986a(boolean b) {
        super(new ArrayList<>());
    }

    T8065986a(boolean b1, boolean b2) {
        super(()->{});
    }

    T8065986a(boolean b1, boolean b2, boolean b3) {
        super(T8065986a::m);
    }

    T8065986a(boolean cond, Object o1, Object o2) {
        super(cond ? o1 : o2);
    }

    static void m() { }
}
