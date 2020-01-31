

class MethodReference37 {

    interface SAM1<R> {
        R invoke();
    }

    interface SAM2<R, A> {
        R invoke(A a);
    }

    static class Outer {
        class Inner { }

        static void test1() {
            SAM2<Inner, Outer> sam = Inner::new;
        }

        void test2() {
            SAM1<Inner> sam0 = Inner::new;
            SAM2<Inner, Outer> sam1 = Inner::new;
        }
    }

    static void test1() {
        SAM2<Outer.Inner, Outer> sam = Outer.Inner::new;
    }

    void test2() {
        SAM2<Outer.Inner, Outer> sam1 = Outer.Inner::new;
    }
}
