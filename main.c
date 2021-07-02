#include <libguile.h>

static int inc = 100;

static SCM
apply_inc()
{
  inc++;
  return SCM_UNSPECIFIED;
}

static SCM
set_inc(SCM value)
{
  inc = scm_to_int(value);
  return SCM_UNSPECIFIED;
}

static SCM
print_inc()
{
  return scm_from_int(inc);
}

static void*
register_functions(void* data)
{
  scm_c_define_gsubr("apply_inc", 0, 0, 0, &apply_inc);
  scm_c_define_gsubr("set_inc", 1, 0, 0, &set_inc);
  scm_c_define_gsubr("print_inc", 0, 0, 0, &print_inc);
  return NULL;
}

int
main (int argc, char **argv)
{
  printf("Hello, C world!\n");
  scm_with_guile(&register_functions, NULL);
  scm_c_primitive_load("script.scm");
  printf("Done: C!\n");
  return 0;
}
