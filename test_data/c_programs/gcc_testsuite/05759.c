


extern void abort (void);
union tree_node;
typedef union tree_node *tree;
enum tree_code
{
  LAST_AND_UNUSED_TREE_CODE
};
extern const char tree_code_type[];
struct tree_common
{
  enum tree_code code:8;
};
struct tree_type
{
  struct tree_common common;
  double alias_set;
};
union tree_node
{
  struct tree_common common;
  struct tree_type type;
};
long
foo (t, set)
     tree t;
     double set;
{
  if (tree_code_type[t->common.code] != 't')
    abort ();

  t->type.alias_set = set;

  if (t->common.code == 42)
    return 1;
  else
    return 0;
}
