struct s* f(void);
struct s;
struct s1;
struct s1* f1(void);
struct s2;
struct s2* f2(void);
struct s2;
struct s3;
struct s3* f3(void);
struct s4* f4(void);
struct s4 { int is; };
struct s5 { int is; };
struct s5* f5(void);
struct s6 *ps6;
struct s6* f6(void);
struct s7;
struct s7* f7(void);
struct s8 { int is8; };
struct s4 *f8(struct s8 *p);
enum e* g(void);
enum e;
enum e1;
enum e1* g1(void);
enum e2;
enum e2* g2(void);
enum e2;
enum e3;
enum e3* g3(void);
enum e4* g4(void);
enum e4 { one };
enum e5 { two };
enum e5* g5(void);
enum e6 *pe6;
enum e6* g6(void);
enum e7;
enum e7* g7(void);
enum e8 { three };
enum e4 *g8(enum e8 *p);
