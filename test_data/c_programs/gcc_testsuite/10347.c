void
foo (int i, int j)
{
  typedef int I;
  int (*pf)[2];
  int (*pv)[i];
  int (*pi)[];
  I (*pfI)[2];
  I (*pvI)[i];
  I (*piI)[];
  do { static int x[sizeof(*(i ? pf : pf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pf : pv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pf : pi))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pf : pfI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pf : pvI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pf : piI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pv : pf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pv : pv)); (void)(1 ? (i ? pv : pv) : (__typeof__(**(i ? pv : pv)) (*)[1])0); (void)(1 ? (i ? pv : pv) : (__typeof__(**(i ? pv : pv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? pv : pi)); (void)(1 ? (i ? pv : pi) : (__typeof__(**(i ? pv : pi)) (*)[1])0); (void)(1 ? (i ? pv : pi) : (__typeof__(**(i ? pv : pi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? pv : pfI))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pv : pvI)); (void)(1 ? (i ? pv : pvI) : (__typeof__(**(i ? pv : pvI)) (*)[1])0); (void)(1 ? (i ? pv : pvI) : (__typeof__(**(i ? pv : pvI)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? pv : piI)); (void)(1 ? (i ? pv : piI) : (__typeof__(**(i ? pv : piI)) (*)[1])0); (void)(1 ? (i ? pv : piI) : (__typeof__(**(i ? pv : piI)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? pi : pf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pi : pv)); (void)(1 ? (i ? pi : pv) : (__typeof__(**(i ? pi : pv)) (*)[1])0); (void)(1 ? (i ? pi : pv) : (__typeof__(**(i ? pi : pv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? pi : pi)) x = { 0 }; (void)x; (void)(1 ? i ? pi : pi : (__typeof__(**(i ? pi : pi)) (*)[1])0); (void)(1 ? i ? pi : pi : (__typeof__(**(i ? pi : pi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? pi : pfI))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pi : pvI)); (void)(1 ? (i ? pi : pvI) : (__typeof__(**(i ? pi : pvI)) (*)[1])0); (void)(1 ? (i ? pi : pvI) : (__typeof__(**(i ? pi : pvI)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? pi : piI)) x = { 0 }; (void)x; (void)(1 ? i ? pi : piI : (__typeof__(**(i ? pi : piI)) (*)[1])0); (void)(1 ? i ? pi : piI : (__typeof__(**(i ? pi : piI)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? pfI : pf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pfI : pv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pfI : pi))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pfI : pfI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pfI : pvI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pfI : piI))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? pvI : pf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pvI : pv)); (void)(1 ? (i ? pvI : pv) : (__typeof__(**(i ? pvI : pv)) (*)[1])0); (void)(1 ? (i ? pvI : pv) : (__typeof__(**(i ? pvI : pv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? pvI : pi)); (void)(1 ? (i ? pvI : pi) : (__typeof__(**(i ? pvI : pi)) (*)[1])0); (void)(1 ? (i ? pvI : pi) : (__typeof__(**(i ? pvI : pi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? pvI : pfI))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? pvI : pvI)); (void)(1 ? (i ? pvI : pvI) : (__typeof__(**(i ? pvI : pvI)) (*)[1])0); (void)(1 ? (i ? pvI : pvI) : (__typeof__(**(i ? pvI : pvI)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? pvI : piI)); (void)(1 ? (i ? pvI : piI) : (__typeof__(**(i ? pvI : piI)) (*)[1])0); (void)(1 ? (i ? pvI : piI) : (__typeof__(**(i ? pvI : piI)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? piI : pf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? piI : pv)); (void)(1 ? (i ? piI : pv) : (__typeof__(**(i ? piI : pv)) (*)[1])0); (void)(1 ? (i ? piI : pv) : (__typeof__(**(i ? piI : pv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? piI : pi)) x = { 0 }; (void)x; (void)(1 ? i ? piI : pi : (__typeof__(**(i ? piI : pi)) (*)[1])0); (void)(1 ? i ? piI : pi : (__typeof__(**(i ? piI : pi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? piI : pfI))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? piI : pvI)); (void)(1 ? (i ? piI : pvI) : (__typeof__(**(i ? piI : pvI)) (*)[1])0); (void)(1 ? (i ? piI : pvI) : (__typeof__(**(i ? piI : pvI)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? piI : piI)) x = { 0 }; (void)x; (void)(1 ? i ? piI : piI : (__typeof__(**(i ? piI : piI)) (*)[1])0); (void)(1 ? i ? piI : piI : (__typeof__(**(i ? piI : piI)) (*)[2])0); } while (0);
  typedef int (*Ti)[i];
  typedef int (*Tj)[j];
  Ti (*qf)[2];
  Ti (*qv)[i];
  Ti (*qi)[];
  Tj (*rf)[2];
  Tj (*rv)[j];
  Tj (*ri)[];
  do { static int x[sizeof(*(i ? qf : qf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qf : qv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qf : qi))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qf : rf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qf : rv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qf : ri))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? qv : qf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? qv : qv)); (void)(1 ? (i ? qv : qv) : (__typeof__(**(i ? qv : qv)) (*)[1])0); (void)(1 ? (i ? qv : qv) : (__typeof__(**(i ? qv : qv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? qv : qi)); (void)(1 ? (i ? qv : qi) : (__typeof__(**(i ? qv : qi)) (*)[1])0); (void)(1 ? (i ? qv : qi) : (__typeof__(**(i ? qv : qi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? qv : rf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? qv : rv)); (void)(1 ? (i ? qv : rv) : (__typeof__(**(i ? qv : rv)) (*)[1])0); (void)(1 ? (i ? qv : rv) : (__typeof__(**(i ? qv : rv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? qv : ri)); (void)(1 ? (i ? qv : ri) : (__typeof__(**(i ? qv : ri)) (*)[1])0); (void)(1 ? (i ? qv : ri) : (__typeof__(**(i ? qv : ri)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? qi : qf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? qi : qv)); (void)(1 ? (i ? qi : qv) : (__typeof__(**(i ? qi : qv)) (*)[1])0); (void)(1 ? (i ? qi : qv) : (__typeof__(**(i ? qi : qv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? qi : qi)) x = { 0 }; (void)x; (void)(1 ? i ? qi : qi : (__typeof__(**(i ? qi : qi)) (*)[1])0); (void)(1 ? i ? qi : qi : (__typeof__(**(i ? qi : qi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? qi : rf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? qi : rv)); (void)(1 ? (i ? qi : rv) : (__typeof__(**(i ? qi : rv)) (*)[1])0); (void)(1 ? (i ? qi : rv) : (__typeof__(**(i ? qi : rv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? qi : ri)) x = { 0 }; (void)x; (void)(1 ? i ? qi : ri : (__typeof__(**(i ? qi : ri)) (*)[1])0); (void)(1 ? i ? qi : ri : (__typeof__(**(i ? qi : ri)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? rf : qf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rf : qv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rf : qi))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rf : rf))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rf : rv))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rf : ri))]; (void)x; } while (0);
  do { static int x[sizeof(*(i ? rv : qf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? rv : qv)); (void)(1 ? (i ? rv : qv) : (__typeof__(**(i ? rv : qv)) (*)[1])0); (void)(1 ? (i ? rv : qv) : (__typeof__(**(i ? rv : qv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? rv : qi)); (void)(1 ? (i ? rv : qi) : (__typeof__(**(i ? rv : qi)) (*)[1])0); (void)(1 ? (i ? rv : qi) : (__typeof__(**(i ? rv : qi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? rv : rf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? rv : rv)); (void)(1 ? (i ? rv : rv) : (__typeof__(**(i ? rv : rv)) (*)[1])0); (void)(1 ? (i ? rv : rv) : (__typeof__(**(i ? rv : rv)) (*)[2])0); } while (0);
  do { (void)sizeof(*(i ? rv : ri)); (void)(1 ? (i ? rv : ri) : (__typeof__(**(i ? rv : ri)) (*)[1])0); (void)(1 ? (i ? rv : ri) : (__typeof__(**(i ? rv : ri)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? ri : qf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? ri : qv)); (void)(1 ? (i ? ri : qv) : (__typeof__(**(i ? ri : qv)) (*)[1])0); (void)(1 ? (i ? ri : qv) : (__typeof__(**(i ? ri : qv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? ri : qi)) x = { 0 }; (void)x; (void)(1 ? i ? ri : qi : (__typeof__(**(i ? ri : qi)) (*)[1])0); (void)(1 ? i ? ri : qi : (__typeof__(**(i ? ri : qi)) (*)[2])0); } while (0);
  do { static int x[sizeof(*(i ? ri : rf))]; (void)x; } while (0);
  do { (void)sizeof(*(i ? ri : rv)); (void)(1 ? (i ? ri : rv) : (__typeof__(**(i ? ri : rv)) (*)[1])0); (void)(1 ? (i ? ri : rv) : (__typeof__(**(i ? ri : rv)) (*)[2])0); } while (0);
  do { __typeof__(*(i ? ri : ri)) x = { 0 }; (void)x; (void)(1 ? i ? ri : ri : (__typeof__(**(i ? ri : ri)) (*)[1])0); (void)(1 ? i ? ri : ri : (__typeof__(**(i ? ri : ri)) (*)[2])0); } while (0);
}
