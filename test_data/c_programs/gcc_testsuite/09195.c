




static unsigned long sum;
static void *stack_base;


static void
mark_maybe_pointer (void *p)
{
  sum ^= (unsigned long) p;
}

static inline void __attribute__ ((no_sanitize_address))
mark_memory (void **start, void **end)
{
  void **pp;

  if (end < start)
    {
      void **tem = start;
      start = end;
      end = tem;
    }

  for (pp = start; pp < end; pp++)
    {

      void *p = *pp;

      mark_maybe_pointer (p);
    }
}

static void
mark_stack (void)
{
  void *end;
  mark_memory (stack_base, &end);
}

void
garbage_collect (void)
{
  mark_stack ();
}

int
main (void)
{
  void *dummy;
  stack_base = &dummy;
  garbage_collect ();
  return 0;
}
