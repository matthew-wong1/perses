



enum EnumPrivateConstructor {
    RED(255, 0, 0),
    GREEN(0, 255, 0),
    BLUE(0, 0, 255);

    private int r, g, b;
    private EnumPrivateConstructor(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }
}
