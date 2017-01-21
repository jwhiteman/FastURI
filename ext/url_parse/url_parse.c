#include "url_parse.h"
#include "parse_machine.h"

VALUE cURLParse;

#define id_ivar_uri rb_intern("@uri")
#define id_ivar_parsed_results rb_intern("@parsed_results")

VALUE
URLParse_set_uri(void *void_self, const char *sptr, size_t len)
{
  VALUE self = (VALUE)void_self;
  VALUE v    = rb_str_new(sptr, len);
  VALUE h    = rb_ivar_get(self, id_ivar_parsed_results);

  ID id_uri = rb_intern("uri");
  rb_hash_aset(h, ID2SYM(id_uri), v);

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
