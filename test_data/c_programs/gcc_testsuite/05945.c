


extern void exit (int);
extern void *ggc_alloc (long unsigned int);
typedef struct dw_attr_struct *dw_attr_ref;
typedef struct dw_attr_struct
{
  int dw_attr;
}
dw_attr_node;
void
foo (int attr_kind, unsigned long offset)
{
  dw_attr_ref attr = (dw_attr_ref) ggc_alloc (sizeof (dw_attr_node));
  attr->dw_attr = attr_kind;
  if (attr != ((void *)0))
    exit (0);
}
