



public class T6294779c<X> {

    interface A {}

    interface B {}

    interface C {}

    interface I1 {
        T6294779c<? extends A> get();
    }

    interface I2 {
        T6294779c<? extends B> get();
    }

    interface I3 {
        T6294779c<? extends C> get();
    }

    interface I4 extends I1, I2, I3 {}
}
