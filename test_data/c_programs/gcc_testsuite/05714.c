


struct _fat_ptr
{
  unsigned char *curr;
  unsigned char *base;
  unsigned char *last_plus_one;
};
int Cyc_string_ungetc (int ignore, struct _fat_ptr *sptr);
int
Cyc_string_ungetc (int ignore, struct _fat_ptr *sptr)
{
  struct _fat_ptr *_T0;
  struct _fat_ptr *_T1;
  struct _fat_ptr _T2;
  int _T3;
  struct _fat_ptr _ans;
  int _change;

  {
    _T0 = sptr;
    _T1 = sptr;
    _T2 = *sptr;
    _T3 = -1;
    _ans = _T2;
    _change = -1;
    _ans.curr += 4294967295U;
    *sptr = _ans;
    return (0);
  }
}
