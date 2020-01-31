extern void abort (void);

extern int fails;







typedef struct { _Complex float a; } Scf1; typedef struct { _Complex float a; _Complex float b; } Scf2; typedef struct { _Complex float a; _Complex float b; _Complex float c; } Scf3; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; } Scf4; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; } Scf5; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; } Scf6; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; } Scf7; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; } Scf8; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; } Scf9; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; } Scf10; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; } Scf11; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; _Complex float l; } Scf12; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; _Complex float l; _Complex float m; } Scf13; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; _Complex float l; _Complex float m; _Complex float n; } Scf14; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; _Complex float l; _Complex float m; _Complex float n; _Complex float o; } Scf15; typedef struct { _Complex float a; _Complex float b; _Complex float c; _Complex float d; _Complex float e; _Complex float f; _Complex float g; _Complex float h; _Complex float i; _Complex float j; _Complex float k; _Complex float l; _Complex float m; _Complex float n; _Complex float o; _Complex float p; } Scf16;
void checkScf1 (Scf1 x, _Complex float y) { if (x.a != y) abort (); } void checkScf2 (Scf2 x, _Complex float y) { if (x.a != y || x.b != y+1 ) abort (); } void checkScf3 (Scf3 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 ) abort (); } void checkScf4 (Scf4 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3) abort (); } void checkScf5 (Scf5 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4) abort (); } void checkScf6 (Scf6 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5) abort (); } void checkScf7 (Scf7 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6) abort (); } void checkScf8 (Scf8 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7) abort (); } void checkScf9 (Scf9 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8) abort (); } void checkScf10 (Scf10 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9) abort (); } void checkScf11 (Scf11 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10) abort (); } void checkScf12 (Scf12 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11) abort (); } void checkScf13 (Scf13 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12) abort (); } void checkScf14 (Scf14 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13) abort (); } void checkScf15 (Scf15 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14) abort (); } void checkScf16 (Scf16 x, _Complex float y) { if (x.a != y || x.b != y+1 || x.c != y+2 || x.d != y+3 || x.e != y+4 || x.f != y+5 || x.g != y+6 || x.h != y+7 || x.i != y+8 || x.j != y+9 || x.k != y+10 || x.l != y+11 || x.m != y+12 || x.n != y+13 || x.o != y+14 || x.p != y+15) abort (); }

Scf13 g1sScf13, g2sScf13, g3sScf13, g4sScf13; Scf13 g5sScf13, g6sScf13, g7sScf13, g8sScf13; Scf13 g9sScf13, g10sScf13, g11sScf13, g12sScf13; Scf13 g13sScf13, g14sScf13, g15sScf13, g16sScf13; extern void initScf13 (Scf13 *p, _Complex float x); extern void checkgScf13 (void); extern void testScf13 (Scf13 s1, Scf13 s2, Scf13 s3, Scf13 s4, Scf13 s5, Scf13 s6, Scf13 s7, Scf13 s8, Scf13 s9, Scf13 s10, Scf13 s11, Scf13 s12, Scf13 s13, Scf13 s14, Scf13 s15, Scf13 s16); extern void testvaScf13 (int n, ...); void test2_Scf13 (Scf13 s1, Scf13 s2, Scf13 s3, Scf13 s4, Scf13 s5, Scf13 s6, Scf13 s7, Scf13 s8) { testScf13 (s1, g2sScf13, s2, g4sScf13, s3, g6sScf13, s4, g8sScf13, s5, g10sScf13, s6, g12sScf13, s7, g14sScf13, s8, g16sScf13); } void testitScf13 (void) { ; ; initScf13 ( &g1sScf13, (_Complex float)1); initScf13 ( &g2sScf13, (_Complex float)2); initScf13 ( &g3sScf13, (_Complex float)3); initScf13 ( &g4sScf13, (_Complex float)4); initScf13 ( &g5sScf13, (_Complex float)5); initScf13 ( &g6sScf13, (_Complex float)6); initScf13 ( &g7sScf13, (_Complex float)7); initScf13 ( &g8sScf13, (_Complex float)8); initScf13 ( &g9sScf13, (_Complex float)9); initScf13 (&g10sScf13, (_Complex float)10); initScf13 (&g11sScf13, (_Complex float)11); initScf13 (&g12sScf13, (_Complex float)12); initScf13 (&g13sScf13, (_Complex float)13); initScf13 (&g14sScf13, (_Complex float)14); initScf13 (&g15sScf13, (_Complex float)15); initScf13 (&g16sScf13, (_Complex float)16); checkgScf13 (); ; ; ; testScf13 (g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13, g13sScf13, g14sScf13, g15sScf13, g16sScf13); ; ; ; ; testvaScf13 (1, g1sScf13); ; testvaScf13 (2, g1sScf13, g2sScf13); ; testvaScf13 (3, g1sScf13, g2sScf13, g3sScf13); ; testvaScf13 (4, g1sScf13, g2sScf13, g3sScf13, g4sScf13); ; testvaScf13 (5, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13); ; testvaScf13 (6, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13); ; testvaScf13 (7, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13); ; testvaScf13 (8, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13); ; testvaScf13 (9, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13); ; testvaScf13 (10, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13); ; testvaScf13 (11, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13); ; testvaScf13 (12, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13); ; testvaScf13 (13, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13, g13sScf13); ; testvaScf13 (14, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13, g13sScf13, g14sScf13); ; testvaScf13 (15, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13, g13sScf13, g14sScf13, g15sScf13); ; testvaScf13 (16, g1sScf13, g2sScf13, g3sScf13, g4sScf13, g5sScf13, g6sScf13, g7sScf13, g8sScf13, g9sScf13, g10sScf13, g11sScf13, g12sScf13, g13sScf13, g14sScf13, g15sScf13, g16sScf13); ; ; ; test2_Scf13 (g1sScf13, g3sScf13, g5sScf13, g7sScf13, g9sScf13, g11sScf13, g13sScf13, g15sScf13); ; }
Scf14 g1sScf14, g2sScf14, g3sScf14, g4sScf14; Scf14 g5sScf14, g6sScf14, g7sScf14, g8sScf14; Scf14 g9sScf14, g10sScf14, g11sScf14, g12sScf14; Scf14 g13sScf14, g14sScf14, g15sScf14, g16sScf14; extern void initScf14 (Scf14 *p, _Complex float x); extern void checkgScf14 (void); extern void testScf14 (Scf14 s1, Scf14 s2, Scf14 s3, Scf14 s4, Scf14 s5, Scf14 s6, Scf14 s7, Scf14 s8, Scf14 s9, Scf14 s10, Scf14 s11, Scf14 s12, Scf14 s13, Scf14 s14, Scf14 s15, Scf14 s16); extern void testvaScf14 (int n, ...); void test2_Scf14 (Scf14 s1, Scf14 s2, Scf14 s3, Scf14 s4, Scf14 s5, Scf14 s6, Scf14 s7, Scf14 s8) { testScf14 (s1, g2sScf14, s2, g4sScf14, s3, g6sScf14, s4, g8sScf14, s5, g10sScf14, s6, g12sScf14, s7, g14sScf14, s8, g16sScf14); } void testitScf14 (void) { ; ; initScf14 ( &g1sScf14, (_Complex float)1); initScf14 ( &g2sScf14, (_Complex float)2); initScf14 ( &g3sScf14, (_Complex float)3); initScf14 ( &g4sScf14, (_Complex float)4); initScf14 ( &g5sScf14, (_Complex float)5); initScf14 ( &g6sScf14, (_Complex float)6); initScf14 ( &g7sScf14, (_Complex float)7); initScf14 ( &g8sScf14, (_Complex float)8); initScf14 ( &g9sScf14, (_Complex float)9); initScf14 (&g10sScf14, (_Complex float)10); initScf14 (&g11sScf14, (_Complex float)11); initScf14 (&g12sScf14, (_Complex float)12); initScf14 (&g13sScf14, (_Complex float)13); initScf14 (&g14sScf14, (_Complex float)14); initScf14 (&g15sScf14, (_Complex float)15); initScf14 (&g16sScf14, (_Complex float)16); checkgScf14 (); ; ; ; testScf14 (g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14, g13sScf14, g14sScf14, g15sScf14, g16sScf14); ; ; ; ; testvaScf14 (1, g1sScf14); ; testvaScf14 (2, g1sScf14, g2sScf14); ; testvaScf14 (3, g1sScf14, g2sScf14, g3sScf14); ; testvaScf14 (4, g1sScf14, g2sScf14, g3sScf14, g4sScf14); ; testvaScf14 (5, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14); ; testvaScf14 (6, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14); ; testvaScf14 (7, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14); ; testvaScf14 (8, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14); ; testvaScf14 (9, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14); ; testvaScf14 (10, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14); ; testvaScf14 (11, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14); ; testvaScf14 (12, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14); ; testvaScf14 (13, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14, g13sScf14); ; testvaScf14 (14, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14, g13sScf14, g14sScf14); ; testvaScf14 (15, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14, g13sScf14, g14sScf14, g15sScf14); ; testvaScf14 (16, g1sScf14, g2sScf14, g3sScf14, g4sScf14, g5sScf14, g6sScf14, g7sScf14, g8sScf14, g9sScf14, g10sScf14, g11sScf14, g12sScf14, g13sScf14, g14sScf14, g15sScf14, g16sScf14); ; ; ; test2_Scf14 (g1sScf14, g3sScf14, g5sScf14, g7sScf14, g9sScf14, g11sScf14, g13sScf14, g15sScf14); ; }
Scf15 g1sScf15, g2sScf15, g3sScf15, g4sScf15; Scf15 g5sScf15, g6sScf15, g7sScf15, g8sScf15; Scf15 g9sScf15, g10sScf15, g11sScf15, g12sScf15; Scf15 g13sScf15, g14sScf15, g15sScf15, g16sScf15; extern void initScf15 (Scf15 *p, _Complex float x); extern void checkgScf15 (void); extern void testScf15 (Scf15 s1, Scf15 s2, Scf15 s3, Scf15 s4, Scf15 s5, Scf15 s6, Scf15 s7, Scf15 s8, Scf15 s9, Scf15 s10, Scf15 s11, Scf15 s12, Scf15 s13, Scf15 s14, Scf15 s15, Scf15 s16); extern void testvaScf15 (int n, ...); void test2_Scf15 (Scf15 s1, Scf15 s2, Scf15 s3, Scf15 s4, Scf15 s5, Scf15 s6, Scf15 s7, Scf15 s8) { testScf15 (s1, g2sScf15, s2, g4sScf15, s3, g6sScf15, s4, g8sScf15, s5, g10sScf15, s6, g12sScf15, s7, g14sScf15, s8, g16sScf15); } void testitScf15 (void) { ; ; initScf15 ( &g1sScf15, (_Complex float)1); initScf15 ( &g2sScf15, (_Complex float)2); initScf15 ( &g3sScf15, (_Complex float)3); initScf15 ( &g4sScf15, (_Complex float)4); initScf15 ( &g5sScf15, (_Complex float)5); initScf15 ( &g6sScf15, (_Complex float)6); initScf15 ( &g7sScf15, (_Complex float)7); initScf15 ( &g8sScf15, (_Complex float)8); initScf15 ( &g9sScf15, (_Complex float)9); initScf15 (&g10sScf15, (_Complex float)10); initScf15 (&g11sScf15, (_Complex float)11); initScf15 (&g12sScf15, (_Complex float)12); initScf15 (&g13sScf15, (_Complex float)13); initScf15 (&g14sScf15, (_Complex float)14); initScf15 (&g15sScf15, (_Complex float)15); initScf15 (&g16sScf15, (_Complex float)16); checkgScf15 (); ; ; ; testScf15 (g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15, g13sScf15, g14sScf15, g15sScf15, g16sScf15); ; ; ; ; testvaScf15 (1, g1sScf15); ; testvaScf15 (2, g1sScf15, g2sScf15); ; testvaScf15 (3, g1sScf15, g2sScf15, g3sScf15); ; testvaScf15 (4, g1sScf15, g2sScf15, g3sScf15, g4sScf15); ; testvaScf15 (5, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15); ; testvaScf15 (6, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15); ; testvaScf15 (7, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15); ; testvaScf15 (8, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15); ; testvaScf15 (9, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15); ; testvaScf15 (10, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15); ; testvaScf15 (11, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15); ; testvaScf15 (12, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15); ; testvaScf15 (13, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15, g13sScf15); ; testvaScf15 (14, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15, g13sScf15, g14sScf15); ; testvaScf15 (15, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15, g13sScf15, g14sScf15, g15sScf15); ; testvaScf15 (16, g1sScf15, g2sScf15, g3sScf15, g4sScf15, g5sScf15, g6sScf15, g7sScf15, g8sScf15, g9sScf15, g10sScf15, g11sScf15, g12sScf15, g13sScf15, g14sScf15, g15sScf15, g16sScf15); ; ; ; test2_Scf15 (g1sScf15, g3sScf15, g5sScf15, g7sScf15, g9sScf15, g11sScf15, g13sScf15, g15sScf15); ; }
Scf16 g1sScf16, g2sScf16, g3sScf16, g4sScf16; Scf16 g5sScf16, g6sScf16, g7sScf16, g8sScf16; Scf16 g9sScf16, g10sScf16, g11sScf16, g12sScf16; Scf16 g13sScf16, g14sScf16, g15sScf16, g16sScf16; extern void initScf16 (Scf16 *p, _Complex float x); extern void checkgScf16 (void); extern void testScf16 (Scf16 s1, Scf16 s2, Scf16 s3, Scf16 s4, Scf16 s5, Scf16 s6, Scf16 s7, Scf16 s8, Scf16 s9, Scf16 s10, Scf16 s11, Scf16 s12, Scf16 s13, Scf16 s14, Scf16 s15, Scf16 s16); extern void testvaScf16 (int n, ...); void test2_Scf16 (Scf16 s1, Scf16 s2, Scf16 s3, Scf16 s4, Scf16 s5, Scf16 s6, Scf16 s7, Scf16 s8) { testScf16 (s1, g2sScf16, s2, g4sScf16, s3, g6sScf16, s4, g8sScf16, s5, g10sScf16, s6, g12sScf16, s7, g14sScf16, s8, g16sScf16); } void testitScf16 (void) { ; ; initScf16 ( &g1sScf16, (_Complex float)1); initScf16 ( &g2sScf16, (_Complex float)2); initScf16 ( &g3sScf16, (_Complex float)3); initScf16 ( &g4sScf16, (_Complex float)4); initScf16 ( &g5sScf16, (_Complex float)5); initScf16 ( &g6sScf16, (_Complex float)6); initScf16 ( &g7sScf16, (_Complex float)7); initScf16 ( &g8sScf16, (_Complex float)8); initScf16 ( &g9sScf16, (_Complex float)9); initScf16 (&g10sScf16, (_Complex float)10); initScf16 (&g11sScf16, (_Complex float)11); initScf16 (&g12sScf16, (_Complex float)12); initScf16 (&g13sScf16, (_Complex float)13); initScf16 (&g14sScf16, (_Complex float)14); initScf16 (&g15sScf16, (_Complex float)15); initScf16 (&g16sScf16, (_Complex float)16); checkgScf16 (); ; ; ; testScf16 (g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16, g13sScf16, g14sScf16, g15sScf16, g16sScf16); ; ; ; ; testvaScf16 (1, g1sScf16); ; testvaScf16 (2, g1sScf16, g2sScf16); ; testvaScf16 (3, g1sScf16, g2sScf16, g3sScf16); ; testvaScf16 (4, g1sScf16, g2sScf16, g3sScf16, g4sScf16); ; testvaScf16 (5, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16); ; testvaScf16 (6, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16); ; testvaScf16 (7, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16); ; testvaScf16 (8, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16); ; testvaScf16 (9, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16); ; testvaScf16 (10, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16); ; testvaScf16 (11, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16); ; testvaScf16 (12, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16); ; testvaScf16 (13, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16, g13sScf16); ; testvaScf16 (14, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16, g13sScf16, g14sScf16); ; testvaScf16 (15, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16, g13sScf16, g14sScf16, g15sScf16); ; testvaScf16 (16, g1sScf16, g2sScf16, g3sScf16, g4sScf16, g5sScf16, g6sScf16, g7sScf16, g8sScf16, g9sScf16, g10sScf16, g11sScf16, g12sScf16, g13sScf16, g14sScf16, g15sScf16, g16sScf16); ; ; ; test2_Scf16 (g1sScf16, g3sScf16, g5sScf16, g7sScf16, g9sScf16, g11sScf16, g13sScf16, g15sScf16); ; }




void
struct_by_value_16a_x ()
{





testitScf13 ();
testitScf14 ();
testitScf15 ();
testitScf16 ();




if (fails != 0)
  abort ();


}
