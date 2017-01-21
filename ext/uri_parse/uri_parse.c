#include "uri_parse.h"
#include "parse_machine.h"

VALUE mURIParse;

void
URIParse_set(void *h, const char *sptr, size_t len, unsigned long k)
{
  VALUE hash = (VALUE)h;
  VALUE key  = (ID)k;
  VALUE val  = rb_str_new(sptr, len);

  rb_hash_aset(hash, ID2SYM(key), val);
}

VALUE
URIParse_parse(VALUE self, VALUE uri)
{
  char *dptr = NULL;
  long dlen  = 0;

  dptr = RSTRING_PTR(uri);
  dlen = RSTRING_LEN(uri);

  VALUE hash = rb_hash_new();

  execute((void *)hash, dptr, dlen);

  return hash;
}

void
Init_uri_parse(void)
{
  mURIParse = rb_define_module("URIParse");

  rb_define_singleton_method(mURIParse, "parse", URIParse_parse, 1);
}
