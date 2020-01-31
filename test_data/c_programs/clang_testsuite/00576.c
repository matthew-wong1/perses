__attribute__((regparm(3))) void f1(int a, int b, int c, int d);
void g1() {
  f1(41, 42, 43, 44);
}
struct s1 {
  int x1;
};
__attribute__((regparm(3))) void f2(int a, int b, struct s1 c, int d);
void g2() {
  struct s1 x = {43};
  f2(41, 42, x, 44);
}
struct s2 {
  int x1;
  int x2;
};
__attribute__((regparm(3))) void f3(int a, int b, struct s2 c, int d);
void g3() {
  struct s2 x = {43, 44};
  f3(41, 42, x, 45);
}
__attribute__((regparm(3))) void f4(int a, struct s2 b, int c);
void g4() {
  struct s2 x = {42, 43};
  f4(41, x, 44);
}
struct s3 {
  int x1;
  int x2;
  int x3;
};
__attribute__((regparm(3))) void f5(int a, struct s3 b, int c);
void g5() {
  struct s3 x = {42, 43, 44};
  f5(41, x, 45);
}
__attribute__((regparm(3))) void f6(struct s3 a, int b);
void g6() {
  struct s3 x = {41, 42, 43};
  f6(x, 44);
}
struct s4 {
  int x1;
  int x2;
  int x3;
  int x4;
};
__attribute__((regparm(3))) void f7(struct s4 a, int b);
void g7() {
  struct s4 x = {41, 42, 43, 44};
  f7(x, 45);
}
__attribute__((regparm(3))) void f8(float a, int b);
void g8(void) {
  f8(41, 42);
}
struct s5 {
  float x1;
};
__attribute__((regparm(3))) void f9(struct s5 a, int b);
void g9(void) {
  struct s5 x = {41};
  f9(x, 42);
}
struct s6 {
  float x1;
  int x2;
};
__attribute__((regparm(3))) void f10(struct s6 a, int b);
void g10(void) {
  struct s6 x = {41, 42};
  f10(x, 43);
}
struct s7 {
  float x1;
  int x2;
  float x3;
};
__attribute__((regparm(3))) void f11(struct s7 a, int b);
void g11(void) {
  struct s7 x = {41, 42, 43};
  f11(x, 44);
}
struct s8 {
  float x1;
  float x2;
};
__attribute__((regparm(3))) void f12(struct s8 a, int b);
void g12(void) {
  struct s8 x = {41, 42};
  f12(x, 43);
}
struct s9 {
  float x1;
  float x2;
  float x3;
};
__attribute__((regparm(3))) void f13(struct s9 a, int b);
void g13(void) {
  struct s9 x = {41, 42, 43};
  f13(x, 44);
}
struct s10 {
  double x1;
};
__attribute__((regparm(3))) void f14(struct s10 a, int b, int c);
void g14(void) {
  struct s10 x = { 41 };
  f14(x, 42, 43);
}
struct s11 {
  double x1;
  double x2;
};
__attribute__((regparm(3))) void f15(struct s11 a, int b);
void g15(void) {
  struct s11 x = { 41, 42 };
  f15(x, 43);
}
struct s12 {
  double x1;
  float x2;
};
__attribute__((regparm(3))) void f16(struct s12 a, int b);
void g16(void) {
  struct s12 x = { 41, 42 };
  f16(x, 43);
}
__attribute__((regparm(3))) struct s12 f17(int a, int b, int c);
void g17(void) {
  f17(41, 42, 43);
}
struct s13 {
  struct inner {
    float x;
  } y;
};
__attribute__((regparm(3))) void f18(struct s13 a, int b, int c, int d);
void g18(void) {
  struct s13 x = {{41}};
  f18(x, 42, 43, 44);
}
