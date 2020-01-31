



import java.lang.annotation.*;

@Repeatable(Foos.class)
@interface Foo {}

@Target(ElementType.ANNOTATION_TYPE)
@interface Foos {
    Foo[] value();
}

public class RepeatingTargetNotAllowed {
    @Foo @Foo int f = 0;
}
