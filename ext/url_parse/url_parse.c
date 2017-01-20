#include "url_parse.h"
#include "parse_machine.h"

VALUE cURLParse;

VALUE
URLParse_init(VALUE self, VALUE data)
{
  char *dptr = NULL;
  long dlen  = 0;

  dptr    = RSTRING_PTR(data);
  dlen    = RSTRING_LEN(data);
  ID ivar = rb_intern("@s");
  VALUE s = rb_str_new(dptr, dlen);

  rb_ivar_set(self, ivar, s);

  return self;
}

VALUE
URLParse_parse(VALUE self)
{
  char *dptr = NULL;
  long dlen  = 0;

  ID ivar = rb_intern("@s");
  VALUE s = rb_ivar_get(self, ivar);
  dptr    = RSTRING_PTR(s);
  dlen    = RSTRING_LEN(s);

  execute(dptr, dlen);

  return Qnil;
}

void
Init_url_parse(void)
{
  cURLParse = rb_define_class("URLParse", rb_cObject);

  rb_define_method(cURLParse, "initialize", URLParse_init, 1);
  rb_define_method(cURLParse, "parse", URLParse_parse, 0);
}
