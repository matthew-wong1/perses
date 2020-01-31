extern void abort (void);

extern int fails;







typedef struct { _Complex long double a; } Scld1; typedef struct { _Complex long double a; _Complex long double b; } Scld2; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; } Scld3; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; } Scld4; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; } Scld5; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; } Scld6; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; } Scld7; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; } Scld8; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; } Scld9; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; } Scld10; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; } Scld11; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; _Complex long double l; } Scld12; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; _Complex long double l; _Complex long double m; } Scld13; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; _Complex long double l; _Complex long double m; _Complex long double n; } Scld14; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; _Complex long double l; _Complex long double m; _Complex long double n; _Complex long double o; } Scld15; typedef struct { _Complex long double a; _Complex long double b; _Complex long double c; _Complex long double d; _Complex long double e; _Complex long double f; _Complex long double g; _Complex long double h; _Complex long double i; _Complex long double j; _Complex long double k; _Complex long double l; _Complex long double m; _Complex long double n; _Complex long double o; _Complex long double p; } Scld16;
void checkScld1 (Scld1 x, _Complex long double y) { if (x.a != y) abort (); } void checkScld2 (Scld2 x, _Complex long double y) { if (x.a != y || x.b != y+1 ) abort (); } void checkScld3 (Scld3 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 ) abort (); } void checkScld4 (Scld4 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3) abort (); } void checkScld5 (Scld5 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4) abort (); } void checkScld6 (Scld6 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5) abort (); } void checkScld7 (Scld7 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6) abort (); } void checkScld8 (Scld8 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7) abort (); } void checkScld9 (Scld9 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8) abort (); } void checkScld10 (Scld10 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9) abort (); } void checkScld11 (Scld11 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10) abort (); } void checkScld12 (Scld12 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11) abort (); } void checkScld13 (Scld13 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12) abort (); } void checkScld14 (Scld14 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13) abort (); } void checkScld15 (Scld15 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14) abort (); } void checkScld16 (Scld16 x, _Complex long double y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14 || x.p != y+15) abort (); }

Scld13 g1sScld13, g2sScld13, g3sScld13, g4sScld13; Scld13 g5sScld13, g6sScld13, g7sScld13, g8sScld13; Scld13 g9sScld13, g10sScld13, g11sScld13, g12sScld13; Scld13 g13sScld13, g14sScld13, g15sScld13, g16sScld13; extern void initScld13 (Scld13 *p, _Complex long double x); extern void checkgScld13 (void); extern void testScld13 (Scld13 s1, Scld13 s2, Scld13 s3, Scld13 s4, Scld13 s5, Scld13 s6, Scld13 s7, Scld13 s8, Scld13 s9, Scld13 s10, Scld13 s11, Scld13 s12, Scld13 s13, Scld13 s14, Scld13 s15, Scld13 s16); extern void testvaScld13 (int n, ...); void test2_Scld13 (Scld13 s1, Scld13 s2, Scld13 s3, Scld13 s4, Scld13 s5, Scld13 s6, Scld13 s7, Scld13 s8) { testScld13 (s1, g2sScld13, s2, g4sScld13, s3, g6sScld13, s4, g8sScld13, s5, g10sScld13, s6, g12sScld13, s7, g14sScld13, s8, g16sScld13); } void testitScld13 (void) { ; ; initScld13 ( &g1sScld13, (_Complex long double)1); initScld13 ( &g2sScld13, (_Complex long double)2); initScld13 ( &g3sScld13, (_Complex long double)3); initScld13 ( &g4sScld13, (_Complex long double)4); initScld13 ( &g5sScld13, (_Complex long double)5); initScld13 ( &g6sScld13, (_Complex long double)6); initScld13 ( &g7sScld13, (_Complex long double)7); initScld13 ( &g8sScld13, (_Complex long double)8); initScld13 ( &g9sScld13, (_Complex long double)9); initScld13 (&g10sScld13, (_Complex long double)10); initScld13 (&g11sScld13, (_Complex long double)11); initScld13 (&g12sScld13, (_Complex long double)12); initScld13 (&g13sScld13, (_Complex long double)13); initScld13 (&g14sScld13, (_Complex long double)14); initScld13 (&g15sScld13, (_Complex long double)15); initScld13 (&g16sScld13, (_Complex long double)16); checkgScld13 (); ; ; ; testScld13 (g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13, g13sScld13, g14sScld13, g15sScld13, g16sScld13); ; ; ; ; testvaScld13 (1, g1sScld13); ; testvaScld13 (2, g1sScld13, g2sScld13); ; testvaScld13 (3, g1sScld13, g2sScld13, g3sScld13); ; testvaScld13 (4, g1sScld13, g2sScld13, g3sScld13, g4sScld13); ; testvaScld13 (5, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13); ; testvaScld13 (6, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13); ; testvaScld13 (7, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13); ; testvaScld13 (8, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13); ; testvaScld13 (9, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13); ; testvaScld13 (10, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13); ; testvaScld13 (11, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13); ; testvaScld13 (12, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13); ; testvaScld13 (13, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13, g13sScld13); ; testvaScld13 (14, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13, g13sScld13, g14sScld13); ; testvaScld13 (15, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13, g13sScld13, g14sScld13, g15sScld13); ; testvaScld13 (16, g1sScld13, g2sScld13, g3sScld13, g4sScld13, g5sScld13, g6sScld13, g7sScld13, g8sScld13, g9sScld13, g10sScld13, g11sScld13, g12sScld13, g13sScld13, g14sScld13, g15sScld13, g16sScld13); ; ; ; test2_Scld13 (g1sScld13, g3sScld13, g5sScld13, g7sScld13, g9sScld13, g11sScld13, g13sScld13, g15sScld13); ; }
Scld14 g1sScld14, g2sScld14, g3sScld14, g4sScld14; Scld14 g5sScld14, g6sScld14, g7sScld14, g8sScld14; Scld14 g9sScld14, g10sScld14, g11sScld14, g12sScld14; Scld14 g13sScld14, g14sScld14, g15sScld14, g16sScld14; extern void initScld14 (Scld14 *p, _Complex long double x); extern void checkgScld14 (void); extern void testScld14 (Scld14 s1, Scld14 s2, Scld14 s3, Scld14 s4, Scld14 s5, Scld14 s6, Scld14 s7, Scld14 s8, Scld14 s9, Scld14 s10, Scld14 s11, Scld14 s12, Scld14 s13, Scld14 s14, Scld14 s15, Scld14 s16); extern void testvaScld14 (int n, ...); void test2_Scld14 (Scld14 s1, Scld14 s2, Scld14 s3, Scld14 s4, Scld14 s5, Scld14 s6, Scld14 s7, Scld14 s8) { testScld14 (s1, g2sScld14, s2, g4sScld14, s3, g6sScld14, s4, g8sScld14, s5, g10sScld14, s6, g12sScld14, s7, g14sScld14, s8, g16sScld14); } void testitScld14 (void) { ; ; initScld14 ( &g1sScld14, (_Complex long double)1); initScld14 ( &g2sScld14, (_Complex long double)2); initScld14 ( &g3sScld14, (_Complex long double)3); initScld14 ( &g4sScld14, (_Complex long double)4); initScld14 ( &g5sScld14, (_Complex long double)5); initScld14 ( &g6sScld14, (_Complex long double)6); initScld14 ( &g7sScld14, (_Complex long double)7); initScld14 ( &g8sScld14, (_Complex long double)8); initScld14 ( &g9sScld14, (_Complex long double)9); initScld14 (&g10sScld14, (_Complex long double)10); initScld14 (&g11sScld14, (_Complex long double)11); initScld14 (&g12sScld14, (_Complex long double)12); initScld14 (&g13sScld14, (_Complex long double)13); initScld14 (&g14sScld14, (_Complex long double)14); initScld14 (&g15sScld14, (_Complex long double)15); initScld14 (&g16sScld14, (_Complex long double)16); checkgScld14 (); ; ; ; testScld14 (g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14, g13sScld14, g14sScld14, g15sScld14, g16sScld14); ; ; ; ; testvaScld14 (1, g1sScld14); ; testvaScld14 (2, g1sScld14, g2sScld14); ; testvaScld14 (3, g1sScld14, g2sScld14, g3sScld14); ; testvaScld14 (4, g1sScld14, g2sScld14, g3sScld14, g4sScld14); ; testvaScld14 (5, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14); ; testvaScld14 (6, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14); ; testvaScld14 (7, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14); ; testvaScld14 (8, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14); ; testvaScld14 (9, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14); ; testvaScld14 (10, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14); ; testvaScld14 (11, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14); ; testvaScld14 (12, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14); ; testvaScld14 (13, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14, g13sScld14); ; testvaScld14 (14, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14, g13sScld14, g14sScld14); ; testvaScld14 (15, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14, g13sScld14, g14sScld14, g15sScld14); ; testvaScld14 (16, g1sScld14, g2sScld14, g3sScld14, g4sScld14, g5sScld14, g6sScld14, g7sScld14, g8sScld14, g9sScld14, g10sScld14, g11sScld14, g12sScld14, g13sScld14, g14sScld14, g15sScld14, g16sScld14); ; ; ; test2_Scld14 (g1sScld14, g3sScld14, g5sScld14, g7sScld14, g9sScld14, g11sScld14, g13sScld14, g15sScld14); ; }
Scld15 g1sScld15, g2sScld15, g3sScld15, g4sScld15; Scld15 g5sScld15, g6sScld15, g7sScld15, g8sScld15; Scld15 g9sScld15, g10sScld15, g11sScld15, g12sScld15; Scld15 g13sScld15, g14sScld15, g15sScld15, g16sScld15; extern void initScld15 (Scld15 *p, _Complex long double x); extern void checkgScld15 (void); extern void testScld15 (Scld15 s1, Scld15 s2, Scld15 s3, Scld15 s4, Scld15 s5, Scld15 s6, Scld15 s7, Scld15 s8, Scld15 s9, Scld15 s10, Scld15 s11, Scld15 s12, Scld15 s13, Scld15 s14, Scld15 s15, Scld15 s16); extern void testvaScld15 (int n, ...); void test2_Scld15 (Scld15 s1, Scld15 s2, Scld15 s3, Scld15 s4, Scld15 s5, Scld15 s6, Scld15 s7, Scld15 s8) { testScld15 (s1, g2sScld15, s2, g4sScld15, s3, g6sScld15, s4, g8sScld15, s5, g10sScld15, s6, g12sScld15, s7, g14sScld15, s8, g16sScld15); } void testitScld15 (void) { ; ; initScld15 ( &g1sScld15, (_Complex long double)1); initScld15 ( &g2sScld15, (_Complex long double)2); initScld15 ( &g3sScld15, (_Complex long double)3); initScld15 ( &g4sScld15, (_Complex long double)4); initScld15 ( &g5sScld15, (_Complex long double)5); initScld15 ( &g6sScld15, (_Complex long double)6); initScld15 ( &g7sScld15, (_Complex long double)7); initScld15 ( &g8sScld15, (_Complex long double)8); initScld15 ( &g9sScld15, (_Complex long double)9); initScld15 (&g10sScld15, (_Complex long double)10); initScld15 (&g11sScld15, (_Complex long double)11); initScld15 (&g12sScld15, (_Complex long double)12); initScld15 (&g13sScld15, (_Complex long double)13); initScld15 (&g14sScld15, (_Complex long double)14); initScld15 (&g15sScld15, (_Complex long double)15); initScld15 (&g16sScld15, (_Complex long double)16); checkgScld15 (); ; ; ; testScld15 (g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15, g13sScld15, g14sScld15, g15sScld15, g16sScld15); ; ; ; ; testvaScld15 (1, g1sScld15); ; testvaScld15 (2, g1sScld15, g2sScld15); ; testvaScld15 (3, g1sScld15, g2sScld15, g3sScld15); ; testvaScld15 (4, g1sScld15, g2sScld15, g3sScld15, g4sScld15); ; testvaScld15 (5, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15); ; testvaScld15 (6, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15); ; testvaScld15 (7, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15); ; testvaScld15 (8, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15); ; testvaScld15 (9, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15); ; testvaScld15 (10, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15); ; testvaScld15 (11, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15); ; testvaScld15 (12, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15); ; testvaScld15 (13, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15, g13sScld15); ; testvaScld15 (14, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15, g13sScld15, g14sScld15); ; testvaScld15 (15, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15, g13sScld15, g14sScld15, g15sScld15); ; testvaScld15 (16, g1sScld15, g2sScld15, g3sScld15, g4sScld15, g5sScld15, g6sScld15, g7sScld15, g8sScld15, g9sScld15, g10sScld15, g11sScld15, g12sScld15, g13sScld15, g14sScld15, g15sScld15, g16sScld15); ; ; ; test2_Scld15 (g1sScld15, g3sScld15, g5sScld15, g7sScld15, g9sScld15, g11sScld15, g13sScld15, g15sScld15); ; }
Scld16 g1sScld16, g2sScld16, g3sScld16, g4sScld16; Scld16 g5sScld16, g6sScld16, g7sScld16, g8sScld16; Scld16 g9sScld16, g10sScld16, g11sScld16, g12sScld16; Scld16 g13sScld16, g14sScld16, g15sScld16, g16sScld16; extern void initScld16 (Scld16 *p, _Complex long double x); extern void checkgScld16 (void); extern void testScld16 (Scld16 s1, Scld16 s2, Scld16 s3, Scld16 s4, Scld16 s5, Scld16 s6, Scld16 s7, Scld16 s8, Scld16 s9, Scld16 s10, Scld16 s11, Scld16 s12, Scld16 s13, Scld16 s14, Scld16 s15, Scld16 s16); extern void testvaScld16 (int n, ...); void test2_Scld16 (Scld16 s1, Scld16 s2, Scld16 s3, Scld16 s4, Scld16 s5, Scld16 s6, Scld16 s7, Scld16 s8) { testScld16 (s1, g2sScld16, s2, g4sScld16, s3, g6sScld16, s4, g8sScld16, s5, g10sScld16, s6, g12sScld16, s7, g14sScld16, s8, g16sScld16); } void testitScld16 (void) { ; ; initScld16 ( &g1sScld16, (_Complex long double)1); initScld16 ( &g2sScld16, (_Complex long double)2); initScld16 ( &g3sScld16, (_Complex long double)3); initScld16 ( &g4sScld16, (_Complex long double)4); initScld16 ( &g5sScld16, (_Complex long double)5); initScld16 ( &g6sScld16, (_Complex long double)6); initScld16 ( &g7sScld16, (_Complex long double)7); initScld16 ( &g8sScld16, (_Complex long double)8); initScld16 ( &g9sScld16, (_Complex long double)9); initScld16 (&g10sScld16, (_Complex long double)10); initScld16 (&g11sScld16, (_Complex long double)11); initScld16 (&g12sScld16, (_Complex long double)12); initScld16 (&g13sScld16, (_Complex long double)13); initScld16 (&g14sScld16, (_Complex long double)14); initScld16 (&g15sScld16, (_Complex long double)15); initScld16 (&g16sScld16, (_Complex long double)16); checkgScld16 (); ; ; ; testScld16 (g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16, g13sScld16, g14sScld16, g15sScld16, g16sScld16); ; ; ; ; testvaScld16 (1, g1sScld16); ; testvaScld16 (2, g1sScld16, g2sScld16); ; testvaScld16 (3, g1sScld16, g2sScld16, g3sScld16); ; testvaScld16 (4, g1sScld16, g2sScld16, g3sScld16, g4sScld16); ; testvaScld16 (5, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16); ; testvaScld16 (6, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16); ; testvaScld16 (7, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16); ; testvaScld16 (8, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16); ; testvaScld16 (9, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16); ; testvaScld16 (10, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16); ; testvaScld16 (11, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16); ; testvaScld16 (12, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16); ; testvaScld16 (13, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16, g13sScld16); ; testvaScld16 (14, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16, g13sScld16, g14sScld16); ; testvaScld16 (15, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16, g13sScld16, g14sScld16, g15sScld16); ; testvaScld16 (16, g1sScld16, g2sScld16, g3sScld16, g4sScld16, g5sScld16, g6sScld16, g7sScld16, g8sScld16, g9sScld16, g10sScld16, g11sScld16, g12sScld16, g13sScld16, g14sScld16, g15sScld16, g16sScld16); ; ; ; test2_Scld16 (g1sScld16, g3sScld16, g5sScld16, g7sScld16, g9sScld16, g11sScld16, g13sScld16, g15sScld16); ; }




void
struct_by_value_18a_x ()
{





testitScld13 ();
testitScld14 ();
testitScld15 ();
testitScld16 ();




if (fails != 0)
  abort ();


}
