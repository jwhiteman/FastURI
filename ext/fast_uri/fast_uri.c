#include "fast_uri.h"
#include "parser.h"

VALUE mFastURI;

void
FastURI_set(void *h, const char *sptr, size_t len, unsigned long k)
{
  VALUE hash = (VALUE)h;
  VALUE key  = (ID)k;
  VALUE val  = rb_str_new(sptr, len);

  rb_hash_aset(hash, ID2SYM(key), val);
}

VALUE
FastURI_parse(VALUE self, VALUE uri)
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
Init_fast_uri(void)
{
  mFastURI = rb_define_module("FastURI");

  rb_define_singleton_method(mFastURI, "parse", FastURI_parse, 1);
}
