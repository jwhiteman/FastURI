/*
 * TODO: adopt consistent usage of either URL or URI
 * TODO: change from class to module (?)
*/
#include "url_parse.h"
#include "parse_machine.h"

VALUE cURLParse;

VALUE
URLParse_set(void *void_self, const char *sptr, size_t len, unsigned long k)
{
  VALUE self = (VALUE)void_self;
  VALUE key  = (ID)k;
  VALUE val  = rb_str_new(sptr, len);
  VALUE hash = rb_ivar_get(self, id_ivar_parsed_results);

  rb_hash_aset(hash, ID2SYM(key), val);

  return self;
}

VALUE
URLParse_init(VALUE self, VALUE uri)
{
  char *dptr = NULL;
  long dlen  = 0;

  dptr    = RSTRING_PTR(uri);
  dlen    = RSTRING_LEN(uri);
  VALUE s = rb_str_new(dptr, dlen);

  rb_ivar_set(self, id_ivar_uri, s);

  VALUE h = rb_hash_new();
  rb_ivar_set(self, id_ivar_parsed_results, h);

  return self;
}

VALUE
URLParse_parse(VALUE self)
{
  char *dptr = NULL;
  long dlen  = 0;

  ID ivar = id_ivar_uri;
  VALUE s = rb_ivar_get(self, ivar);
  dptr    = RSTRING_PTR(s);
  dlen    = RSTRING_LEN(s);

  execute((void *)self, dptr, dlen);

  return rb_ivar_get(self, id_ivar_parsed_results);
}

void
Init_url_parse(void)
{
  cURLParse = rb_define_class("URLParse", rb_cObject);

  rb_define_method(cURLParse, "initialize", URLParse_init, 1);
  rb_define_method(cURLParse, "parse", URLParse_parse, 0);
}
