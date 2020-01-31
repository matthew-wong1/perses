extern void abort (void);

extern int fails;


typedef struct { double a; } Sd1; typedef struct { double a; double b; } Sd2; typedef struct { double a; double b; double c; } Sd3; typedef struct { double a; double b; double c; double d; } Sd4; typedef struct { double a; double b; double c; double d; double e; } Sd5; typedef struct { double a; double b; double c; double d; double e; double f; } Sd6; typedef struct { double a; double b; double c; double d; double e; double f; double g; } Sd7; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; } Sd8; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; } Sd9; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; } Sd10; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; } Sd11; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; double l; } Sd12; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; double l; double m; } Sd13; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; double l; double m; double n; } Sd14; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; double l; double m; double n; double o; } Sd15; typedef struct { double a; double b; double c; double d; double e; double f; double g; double h; double i; double j; double k; double l; double m; double n; double o; double p; } Sd16;
void checkSd1 (Sd1 x, double y) { if (x.a != y) abort (); } void checkSd2 (Sd2 x, double y) { if (x.a != y || x.b != y+1 ) abort (); } void checkSd3 (Sd3 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 ) abort (); } void checkSd4 (Sd4 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3) abort (); } void checkSd5 (Sd5 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4) abort (); } void checkSd6 (Sd6 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5) abort (); } void checkSd7 (Sd7 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6) abort (); } void checkSd8 (Sd8 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7) abort (); } void checkSd9 (Sd9 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8) abort (); } void checkSd10 (Sd10 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9) abort (); } void checkSd11 (Sd11 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10) abort (); } void checkSd12 (Sd12 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11) abort (); } void checkSd13 (Sd13 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12) abort (); } void checkSd14 (Sd14 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13) abort (); } void checkSd15 (Sd15 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14) abort (); } void checkSd16 (Sd16 x, double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14 || x.p != y+15) abort (); }

Sd1 g1sSd1, g2sSd1, g3sSd1, g4sSd1; Sd1 g5sSd1, g6sSd1, g7sSd1, g8sSd1; Sd1 g9sSd1, g10sSd1, g11sSd1, g12sSd1; Sd1 g13sSd1, g14sSd1, g15sSd1, g16sSd1; extern void initSd1 (Sd1 *p, double x); extern void checkgSd1 (void); extern void testSd1 (Sd1 s1, Sd1 s2, Sd1 s3, Sd1 s4, Sd1 s5, Sd1 s6, Sd1 s7, Sd1 s8, Sd1 s9, Sd1 s10, Sd1 s11, Sd1 s12, Sd1 s13, Sd1 s14, Sd1 s15, Sd1 s16); extern void testvaSd1 (int n, ...); void test2_Sd1 (Sd1 s1, Sd1 s2, Sd1 s3, Sd1 s4, Sd1 s5, Sd1 s6, Sd1 s7, Sd1 s8) { testSd1 (s1, g2sSd1, s2, g4sSd1, s3, g6sSd1, s4, g8sSd1, s5, g10sSd1, s6, g12sSd1, s7, g14sSd1, s8, g16sSd1); } void testitSd1 (void) { ; ; initSd1 ( &g1sSd1, (double)1); initSd1 ( &g2sSd1, (double)2); initSd1 ( &g3sSd1, (double)3); initSd1 ( &g4sSd1, (double)4); initSd1 ( &g5sSd1, (double)5); initSd1 ( &g6sSd1, (double)6); initSd1 ( &g7sSd1, (double)7); initSd1 ( &g8sSd1, (double)8); initSd1 ( &g9sSd1, (double)9); initSd1 (&g10sSd1, (double)10); initSd1 (&g11sSd1, (double)11); initSd1 (&g12sSd1, (double)12); initSd1 (&g13sSd1, (double)13); initSd1 (&g14sSd1, (double)14); initSd1 (&g15sSd1, (double)15); initSd1 (&g16sSd1, (double)16); checkgSd1 (); ; ; ; testSd1 (g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1, g13sSd1, g14sSd1, g15sSd1, g16sSd1); ; ; ; ; testvaSd1 (1, g1sSd1); ; testvaSd1 (2, g1sSd1, g2sSd1); ; testvaSd1 (3, g1sSd1, g2sSd1, g3sSd1); ; testvaSd1 (4, g1sSd1, g2sSd1, g3sSd1, g4sSd1); ; testvaSd1 (5, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1); ; testvaSd1 (6, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1); ; testvaSd1 (7, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1); ; testvaSd1 (8, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1); ; testvaSd1 (9, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1); ; testvaSd1 (10, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1); ; testvaSd1 (11, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1); ; testvaSd1 (12, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1); ; testvaSd1 (13, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1, g13sSd1); ; testvaSd1 (14, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1, g13sSd1, g14sSd1); ; testvaSd1 (15, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1, g13sSd1, g14sSd1, g15sSd1); ; testvaSd1 (16, g1sSd1, g2sSd1, g3sSd1, g4sSd1, g5sSd1, g6sSd1, g7sSd1, g8sSd1, g9sSd1, g10sSd1, g11sSd1, g12sSd1, g13sSd1, g14sSd1, g15sSd1, g16sSd1); ; ; ; test2_Sd1 (g1sSd1, g3sSd1, g5sSd1, g7sSd1, g9sSd1, g11sSd1, g13sSd1, g15sSd1); ; }
Sd2 g1sSd2, g2sSd2, g3sSd2, g4sSd2; Sd2 g5sSd2, g6sSd2, g7sSd2, g8sSd2; Sd2 g9sSd2, g10sSd2, g11sSd2, g12sSd2; Sd2 g13sSd2, g14sSd2, g15sSd2, g16sSd2; extern void initSd2 (Sd2 *p, double x); extern void checkgSd2 (void); extern void testSd2 (Sd2 s1, Sd2 s2, Sd2 s3, Sd2 s4, Sd2 s5, Sd2 s6, Sd2 s7, Sd2 s8, Sd2 s9, Sd2 s10, Sd2 s11, Sd2 s12, Sd2 s13, Sd2 s14, Sd2 s15, Sd2 s16); extern void testvaSd2 (int n, ...); void test2_Sd2 (Sd2 s1, Sd2 s2, Sd2 s3, Sd2 s4, Sd2 s5, Sd2 s6, Sd2 s7, Sd2 s8) { testSd2 (s1, g2sSd2, s2, g4sSd2, s3, g6sSd2, s4, g8sSd2, s5, g10sSd2, s6, g12sSd2, s7, g14sSd2, s8, g16sSd2); } void testitSd2 (void) { ; ; initSd2 ( &g1sSd2, (double)1); initSd2 ( &g2sSd2, (double)2); initSd2 ( &g3sSd2, (double)3); initSd2 ( &g4sSd2, (double)4); initSd2 ( &g5sSd2, (double)5); initSd2 ( &g6sSd2, (double)6); initSd2 ( &g7sSd2, (double)7); initSd2 ( &g8sSd2, (double)8); initSd2 ( &g9sSd2, (double)9); initSd2 (&g10sSd2, (double)10); initSd2 (&g11sSd2, (double)11); initSd2 (&g12sSd2, (double)12); initSd2 (&g13sSd2, (double)13); initSd2 (&g14sSd2, (double)14); initSd2 (&g15sSd2, (double)15); initSd2 (&g16sSd2, (double)16); checkgSd2 (); ; ; ; testSd2 (g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2, g13sSd2, g14sSd2, g15sSd2, g16sSd2); ; ; ; ; testvaSd2 (1, g1sSd2); ; testvaSd2 (2, g1sSd2, g2sSd2); ; testvaSd2 (3, g1sSd2, g2sSd2, g3sSd2); ; testvaSd2 (4, g1sSd2, g2sSd2, g3sSd2, g4sSd2); ; testvaSd2 (5, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2); ; testvaSd2 (6, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2); ; testvaSd2 (7, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2); ; testvaSd2 (8, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2); ; testvaSd2 (9, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2); ; testvaSd2 (10, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2); ; testvaSd2 (11, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2); ; testvaSd2 (12, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2); ; testvaSd2 (13, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2, g13sSd2); ; testvaSd2 (14, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2, g13sSd2, g14sSd2); ; testvaSd2 (15, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2, g13sSd2, g14sSd2, g15sSd2); ; testvaSd2 (16, g1sSd2, g2sSd2, g3sSd2, g4sSd2, g5sSd2, g6sSd2, g7sSd2, g8sSd2, g9sSd2, g10sSd2, g11sSd2, g12sSd2, g13sSd2, g14sSd2, g15sSd2, g16sSd2); ; ; ; test2_Sd2 (g1sSd2, g3sSd2, g5sSd2, g7sSd2, g9sSd2, g11sSd2, g13sSd2, g15sSd2); ; }
Sd3 g1sSd3, g2sSd3, g3sSd3, g4sSd3; Sd3 g5sSd3, g6sSd3, g7sSd3, g8sSd3; Sd3 g9sSd3, g10sSd3, g11sSd3, g12sSd3; Sd3 g13sSd3, g14sSd3, g15sSd3, g16sSd3; extern void initSd3 (Sd3 *p, double x); extern void checkgSd3 (void); extern void testSd3 (Sd3 s1, Sd3 s2, Sd3 s3, Sd3 s4, Sd3 s5, Sd3 s6, Sd3 s7, Sd3 s8, Sd3 s9, Sd3 s10, Sd3 s11, Sd3 s12, Sd3 s13, Sd3 s14, Sd3 s15, Sd3 s16); extern void testvaSd3 (int n, ...); void test2_Sd3 (Sd3 s1, Sd3 s2, Sd3 s3, Sd3 s4, Sd3 s5, Sd3 s6, Sd3 s7, Sd3 s8) { testSd3 (s1, g2sSd3, s2, g4sSd3, s3, g6sSd3, s4, g8sSd3, s5, g10sSd3, s6, g12sSd3, s7, g14sSd3, s8, g16sSd3); } void testitSd3 (void) { ; ; initSd3 ( &g1sSd3, (double)1); initSd3 ( &g2sSd3, (double)2); initSd3 ( &g3sSd3, (double)3); initSd3 ( &g4sSd3, (double)4); initSd3 ( &g5sSd3, (double)5); initSd3 ( &g6sSd3, (double)6); initSd3 ( &g7sSd3, (double)7); initSd3 ( &g8sSd3, (double)8); initSd3 ( &g9sSd3, (double)9); initSd3 (&g10sSd3, (double)10); initSd3 (&g11sSd3, (double)11); initSd3 (&g12sSd3, (double)12); initSd3 (&g13sSd3, (double)13); initSd3 (&g14sSd3, (double)14); initSd3 (&g15sSd3, (double)15); initSd3 (&g16sSd3, (double)16); checkgSd3 (); ; ; ; testSd3 (g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3, g13sSd3, g14sSd3, g15sSd3, g16sSd3); ; ; ; ; testvaSd3 (1, g1sSd3); ; testvaSd3 (2, g1sSd3, g2sSd3); ; testvaSd3 (3, g1sSd3, g2sSd3, g3sSd3); ; testvaSd3 (4, g1sSd3, g2sSd3, g3sSd3, g4sSd3); ; testvaSd3 (5, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3); ; testvaSd3 (6, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3); ; testvaSd3 (7, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3); ; testvaSd3 (8, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3); ; testvaSd3 (9, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3); ; testvaSd3 (10, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3); ; testvaSd3 (11, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3); ; testvaSd3 (12, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3); ; testvaSd3 (13, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3, g13sSd3); ; testvaSd3 (14, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3, g13sSd3, g14sSd3); ; testvaSd3 (15, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3, g13sSd3, g14sSd3, g15sSd3); ; testvaSd3 (16, g1sSd3, g2sSd3, g3sSd3, g4sSd3, g5sSd3, g6sSd3, g7sSd3, g8sSd3, g9sSd3, g10sSd3, g11sSd3, g12sSd3, g13sSd3, g14sSd3, g15sSd3, g16sSd3); ; ; ; test2_Sd3 (g1sSd3, g3sSd3, g5sSd3, g7sSd3, g9sSd3, g11sSd3, g13sSd3, g15sSd3); ; }
Sd4 g1sSd4, g2sSd4, g3sSd4, g4sSd4; Sd4 g5sSd4, g6sSd4, g7sSd4, g8sSd4; Sd4 g9sSd4, g10sSd4, g11sSd4, g12sSd4; Sd4 g13sSd4, g14sSd4, g15sSd4, g16sSd4; extern void initSd4 (Sd4 *p, double x); extern void checkgSd4 (void); extern void testSd4 (Sd4 s1, Sd4 s2, Sd4 s3, Sd4 s4, Sd4 s5, Sd4 s6, Sd4 s7, Sd4 s8, Sd4 s9, Sd4 s10, Sd4 s11, Sd4 s12, Sd4 s13, Sd4 s14, Sd4 s15, Sd4 s16); extern void testvaSd4 (int n, ...); void test2_Sd4 (Sd4 s1, Sd4 s2, Sd4 s3, Sd4 s4, Sd4 s5, Sd4 s6, Sd4 s7, Sd4 s8) { testSd4 (s1, g2sSd4, s2, g4sSd4, s3, g6sSd4, s4, g8sSd4, s5, g10sSd4, s6, g12sSd4, s7, g14sSd4, s8, g16sSd4); } void testitSd4 (void) { ; ; initSd4 ( &g1sSd4, (double)1); initSd4 ( &g2sSd4, (double)2); initSd4 ( &g3sSd4, (double)3); initSd4 ( &g4sSd4, (double)4); initSd4 ( &g5sSd4, (double)5); initSd4 ( &g6sSd4, (double)6); initSd4 ( &g7sSd4, (double)7); initSd4 ( &g8sSd4, (double)8); initSd4 ( &g9sSd4, (double)9); initSd4 (&g10sSd4, (double)10); initSd4 (&g11sSd4, (double)11); initSd4 (&g12sSd4, (double)12); initSd4 (&g13sSd4, (double)13); initSd4 (&g14sSd4, (double)14); initSd4 (&g15sSd4, (double)15); initSd4 (&g16sSd4, (double)16); checkgSd4 (); ; ; ; testSd4 (g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4, g13sSd4, g14sSd4, g15sSd4, g16sSd4); ; ; ; ; testvaSd4 (1, g1sSd4); ; testvaSd4 (2, g1sSd4, g2sSd4); ; testvaSd4 (3, g1sSd4, g2sSd4, g3sSd4); ; testvaSd4 (4, g1sSd4, g2sSd4, g3sSd4, g4sSd4); ; testvaSd4 (5, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4); ; testvaSd4 (6, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4); ; testvaSd4 (7, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4); ; testvaSd4 (8, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4); ; testvaSd4 (9, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4); ; testvaSd4 (10, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4); ; testvaSd4 (11, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4); ; testvaSd4 (12, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4); ; testvaSd4 (13, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4, g13sSd4); ; testvaSd4 (14, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4, g13sSd4, g14sSd4); ; testvaSd4 (15, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4, g13sSd4, g14sSd4, g15sSd4); ; testvaSd4 (16, g1sSd4, g2sSd4, g3sSd4, g4sSd4, g5sSd4, g6sSd4, g7sSd4, g8sSd4, g9sSd4, g10sSd4, g11sSd4, g12sSd4, g13sSd4, g14sSd4, g15sSd4, g16sSd4); ; ; ; test2_Sd4 (g1sSd4, g3sSd4, g5sSd4, g7sSd4, g9sSd4, g11sSd4, g13sSd4, g15sSd4); ; }
Sd5 g1sSd5, g2sSd5, g3sSd5, g4sSd5; Sd5 g5sSd5, g6sSd5, g7sSd5, g8sSd5; Sd5 g9sSd5, g10sSd5, g11sSd5, g12sSd5; Sd5 g13sSd5, g14sSd5, g15sSd5, g16sSd5; extern void initSd5 (Sd5 *p, double x); extern void checkgSd5 (void); extern void testSd5 (Sd5 s1, Sd5 s2, Sd5 s3, Sd5 s4, Sd5 s5, Sd5 s6, Sd5 s7, Sd5 s8, Sd5 s9, Sd5 s10, Sd5 s11, Sd5 s12, Sd5 s13, Sd5 s14, Sd5 s15, Sd5 s16); extern void testvaSd5 (int n, ...); void test2_Sd5 (Sd5 s1, Sd5 s2, Sd5 s3, Sd5 s4, Sd5 s5, Sd5 s6, Sd5 s7, Sd5 s8) { testSd5 (s1, g2sSd5, s2, g4sSd5, s3, g6sSd5, s4, g8sSd5, s5, g10sSd5, s6, g12sSd5, s7, g14sSd5, s8, g16sSd5); } void testitSd5 (void) { ; ; initSd5 ( &g1sSd5, (double)1); initSd5 ( &g2sSd5, (double)2); initSd5 ( &g3sSd5, (double)3); initSd5 ( &g4sSd5, (double)4); initSd5 ( &g5sSd5, (double)5); initSd5 ( &g6sSd5, (double)6); initSd5 ( &g7sSd5, (double)7); initSd5 ( &g8sSd5, (double)8); initSd5 ( &g9sSd5, (double)9); initSd5 (&g10sSd5, (double)10); initSd5 (&g11sSd5, (double)11); initSd5 (&g12sSd5, (double)12); initSd5 (&g13sSd5, (double)13); initSd5 (&g14sSd5, (double)14); initSd5 (&g15sSd5, (double)15); initSd5 (&g16sSd5, (double)16); checkgSd5 (); ; ; ; testSd5 (g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5, g13sSd5, g14sSd5, g15sSd5, g16sSd5); ; ; ; ; testvaSd5 (1, g1sSd5); ; testvaSd5 (2, g1sSd5, g2sSd5); ; testvaSd5 (3, g1sSd5, g2sSd5, g3sSd5); ; testvaSd5 (4, g1sSd5, g2sSd5, g3sSd5, g4sSd5); ; testvaSd5 (5, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5); ; testvaSd5 (6, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5); ; testvaSd5 (7, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5); ; testvaSd5 (8, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5); ; testvaSd5 (9, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5); ; testvaSd5 (10, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5); ; testvaSd5 (11, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5); ; testvaSd5 (12, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5); ; testvaSd5 (13, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5, g13sSd5); ; testvaSd5 (14, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5, g13sSd5, g14sSd5); ; testvaSd5 (15, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5, g13sSd5, g14sSd5, g15sSd5); ; testvaSd5 (16, g1sSd5, g2sSd5, g3sSd5, g4sSd5, g5sSd5, g6sSd5, g7sSd5, g8sSd5, g9sSd5, g10sSd5, g11sSd5, g12sSd5, g13sSd5, g14sSd5, g15sSd5, g16sSd5); ; ; ; test2_Sd5 (g1sSd5, g3sSd5, g5sSd5, g7sSd5, g9sSd5, g11sSd5, g13sSd5, g15sSd5); ; }
Sd6 g1sSd6, g2sSd6, g3sSd6, g4sSd6; Sd6 g5sSd6, g6sSd6, g7sSd6, g8sSd6; Sd6 g9sSd6, g10sSd6, g11sSd6, g12sSd6; Sd6 g13sSd6, g14sSd6, g15sSd6, g16sSd6; extern void initSd6 (Sd6 *p, double x); extern void checkgSd6 (void); extern void testSd6 (Sd6 s1, Sd6 s2, Sd6 s3, Sd6 s4, Sd6 s5, Sd6 s6, Sd6 s7, Sd6 s8, Sd6 s9, Sd6 s10, Sd6 s11, Sd6 s12, Sd6 s13, Sd6 s14, Sd6 s15, Sd6 s16); extern void testvaSd6 (int n, ...); void test2_Sd6 (Sd6 s1, Sd6 s2, Sd6 s3, Sd6 s4, Sd6 s5, Sd6 s6, Sd6 s7, Sd6 s8) { testSd6 (s1, g2sSd6, s2, g4sSd6, s3, g6sSd6, s4, g8sSd6, s5, g10sSd6, s6, g12sSd6, s7, g14sSd6, s8, g16sSd6); } void testitSd6 (void) { ; ; initSd6 ( &g1sSd6, (double)1); initSd6 ( &g2sSd6, (double)2); initSd6 ( &g3sSd6, (double)3); initSd6 ( &g4sSd6, (double)4); initSd6 ( &g5sSd6, (double)5); initSd6 ( &g6sSd6, (double)6); initSd6 ( &g7sSd6, (double)7); initSd6 ( &g8sSd6, (double)8); initSd6 ( &g9sSd6, (double)9); initSd6 (&g10sSd6, (double)10); initSd6 (&g11sSd6, (double)11); initSd6 (&g12sSd6, (double)12); initSd6 (&g13sSd6, (double)13); initSd6 (&g14sSd6, (double)14); initSd6 (&g15sSd6, (double)15); initSd6 (&g16sSd6, (double)16); checkgSd6 (); ; ; ; testSd6 (g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6, g13sSd6, g14sSd6, g15sSd6, g16sSd6); ; ; ; ; testvaSd6 (1, g1sSd6); ; testvaSd6 (2, g1sSd6, g2sSd6); ; testvaSd6 (3, g1sSd6, g2sSd6, g3sSd6); ; testvaSd6 (4, g1sSd6, g2sSd6, g3sSd6, g4sSd6); ; testvaSd6 (5, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6); ; testvaSd6 (6, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6); ; testvaSd6 (7, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6); ; testvaSd6 (8, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6); ; testvaSd6 (9, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6); ; testvaSd6 (10, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6); ; testvaSd6 (11, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6); ; testvaSd6 (12, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6); ; testvaSd6 (13, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6, g13sSd6); ; testvaSd6 (14, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6, g13sSd6, g14sSd6); ; testvaSd6 (15, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6, g13sSd6, g14sSd6, g15sSd6); ; testvaSd6 (16, g1sSd6, g2sSd6, g3sSd6, g4sSd6, g5sSd6, g6sSd6, g7sSd6, g8sSd6, g9sSd6, g10sSd6, g11sSd6, g12sSd6, g13sSd6, g14sSd6, g15sSd6, g16sSd6); ; ; ; test2_Sd6 (g1sSd6, g3sSd6, g5sSd6, g7sSd6, g9sSd6, g11sSd6, g13sSd6, g15sSd6); ; }
Sd7 g1sSd7, g2sSd7, g3sSd7, g4sSd7; Sd7 g5sSd7, g6sSd7, g7sSd7, g8sSd7; Sd7 g9sSd7, g10sSd7, g11sSd7, g12sSd7; Sd7 g13sSd7, g14sSd7, g15sSd7, g16sSd7; extern void initSd7 (Sd7 *p, double x); extern void checkgSd7 (void); extern void testSd7 (Sd7 s1, Sd7 s2, Sd7 s3, Sd7 s4, Sd7 s5, Sd7 s6, Sd7 s7, Sd7 s8, Sd7 s9, Sd7 s10, Sd7 s11, Sd7 s12, Sd7 s13, Sd7 s14, Sd7 s15, Sd7 s16); extern void testvaSd7 (int n, ...); void test2_Sd7 (Sd7 s1, Sd7 s2, Sd7 s3, Sd7 s4, Sd7 s5, Sd7 s6, Sd7 s7, Sd7 s8) { testSd7 (s1, g2sSd7, s2, g4sSd7, s3, g6sSd7, s4, g8sSd7, s5, g10sSd7, s6, g12sSd7, s7, g14sSd7, s8, g16sSd7); } void testitSd7 (void) { ; ; initSd7 ( &g1sSd7, (double)1); initSd7 ( &g2sSd7, (double)2); initSd7 ( &g3sSd7, (double)3); initSd7 ( &g4sSd7, (double)4); initSd7 ( &g5sSd7, (double)5); initSd7 ( &g6sSd7, (double)6); initSd7 ( &g7sSd7, (double)7); initSd7 ( &g8sSd7, (double)8); initSd7 ( &g9sSd7, (double)9); initSd7 (&g10sSd7, (double)10); initSd7 (&g11sSd7, (double)11); initSd7 (&g12sSd7, (double)12); initSd7 (&g13sSd7, (double)13); initSd7 (&g14sSd7, (double)14); initSd7 (&g15sSd7, (double)15); initSd7 (&g16sSd7, (double)16); checkgSd7 (); ; ; ; testSd7 (g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7, g13sSd7, g14sSd7, g15sSd7, g16sSd7); ; ; ; ; testvaSd7 (1, g1sSd7); ; testvaSd7 (2, g1sSd7, g2sSd7); ; testvaSd7 (3, g1sSd7, g2sSd7, g3sSd7); ; testvaSd7 (4, g1sSd7, g2sSd7, g3sSd7, g4sSd7); ; testvaSd7 (5, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7); ; testvaSd7 (6, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7); ; testvaSd7 (7, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7); ; testvaSd7 (8, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7); ; testvaSd7 (9, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7); ; testvaSd7 (10, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7); ; testvaSd7 (11, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7); ; testvaSd7 (12, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7); ; testvaSd7 (13, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7, g13sSd7); ; testvaSd7 (14, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7, g13sSd7, g14sSd7); ; testvaSd7 (15, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7, g13sSd7, g14sSd7, g15sSd7); ; testvaSd7 (16, g1sSd7, g2sSd7, g3sSd7, g4sSd7, g5sSd7, g6sSd7, g7sSd7, g8sSd7, g9sSd7, g10sSd7, g11sSd7, g12sSd7, g13sSd7, g14sSd7, g15sSd7, g16sSd7); ; ; ; test2_Sd7 (g1sSd7, g3sSd7, g5sSd7, g7sSd7, g9sSd7, g11sSd7, g13sSd7, g15sSd7); ; }
Sd8 g1sSd8, g2sSd8, g3sSd8, g4sSd8; Sd8 g5sSd8, g6sSd8, g7sSd8, g8sSd8; Sd8 g9sSd8, g10sSd8, g11sSd8, g12sSd8; Sd8 g13sSd8, g14sSd8, g15sSd8, g16sSd8; extern void initSd8 (Sd8 *p, double x); extern void checkgSd8 (void); extern void testSd8 (Sd8 s1, Sd8 s2, Sd8 s3, Sd8 s4, Sd8 s5, Sd8 s6, Sd8 s7, Sd8 s8, Sd8 s9, Sd8 s10, Sd8 s11, Sd8 s12, Sd8 s13, Sd8 s14, Sd8 s15, Sd8 s16); extern void testvaSd8 (int n, ...); void test2_Sd8 (Sd8 s1, Sd8 s2, Sd8 s3, Sd8 s4, Sd8 s5, Sd8 s6, Sd8 s7, Sd8 s8) { testSd8 (s1, g2sSd8, s2, g4sSd8, s3, g6sSd8, s4, g8sSd8, s5, g10sSd8, s6, g12sSd8, s7, g14sSd8, s8, g16sSd8); } void testitSd8 (void) { ; ; initSd8 ( &g1sSd8, (double)1); initSd8 ( &g2sSd8, (double)2); initSd8 ( &g3sSd8, (double)3); initSd8 ( &g4sSd8, (double)4); initSd8 ( &g5sSd8, (double)5); initSd8 ( &g6sSd8, (double)6); initSd8 ( &g7sSd8, (double)7); initSd8 ( &g8sSd8, (double)8); initSd8 ( &g9sSd8, (double)9); initSd8 (&g10sSd8, (double)10); initSd8 (&g11sSd8, (double)11); initSd8 (&g12sSd8, (double)12); initSd8 (&g13sSd8, (double)13); initSd8 (&g14sSd8, (double)14); initSd8 (&g15sSd8, (double)15); initSd8 (&g16sSd8, (double)16); checkgSd8 (); ; ; ; testSd8 (g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8, g13sSd8, g14sSd8, g15sSd8, g16sSd8); ; ; ; ; testvaSd8 (1, g1sSd8); ; testvaSd8 (2, g1sSd8, g2sSd8); ; testvaSd8 (3, g1sSd8, g2sSd8, g3sSd8); ; testvaSd8 (4, g1sSd8, g2sSd8, g3sSd8, g4sSd8); ; testvaSd8 (5, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8); ; testvaSd8 (6, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8); ; testvaSd8 (7, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8); ; testvaSd8 (8, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8); ; testvaSd8 (9, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8); ; testvaSd8 (10, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8); ; testvaSd8 (11, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8); ; testvaSd8 (12, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8); ; testvaSd8 (13, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8, g13sSd8); ; testvaSd8 (14, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8, g13sSd8, g14sSd8); ; testvaSd8 (15, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8, g13sSd8, g14sSd8, g15sSd8); ; testvaSd8 (16, g1sSd8, g2sSd8, g3sSd8, g4sSd8, g5sSd8, g6sSd8, g7sSd8, g8sSd8, g9sSd8, g10sSd8, g11sSd8, g12sSd8, g13sSd8, g14sSd8, g15sSd8, g16sSd8); ; ; ; test2_Sd8 (g1sSd8, g3sSd8, g5sSd8, g7sSd8, g9sSd8, g11sSd8, g13sSd8, g15sSd8); ; }



void
struct_by_value_6a_x ()
{




testitSd1 ();
testitSd2 ();
testitSd3 ();
testitSd4 ();
testitSd5 ();
testitSd6 ();
testitSd7 ();
testitSd8 ();



if (fails != 0)
  abort ();


}
