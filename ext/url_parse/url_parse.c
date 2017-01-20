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

  parse_machine *pm = NULL;
  Data_Get_Struct(self, parse_machine, pm);
  execute(dptr, dlen, pm);

  return Qnil;
}

void
URLParse_free(void *data) {
  if(data) {
    free(data);
  }
}

VALUE
URLParse_alloc(VALUE class)
{
  VALUE obj;
  parse_machine *pm = ALLOC_N(parse_machine, 1);
  pm->mark = 0;

  obj = Data_Wrap_Struct(class, NULL, URLParse_free, pm);
  return obj;
}

void
Init_url_parse(void)
{
  cURLParse = rb_define_class("URLParse", rb_cObject);

  rb_define_alloc_func(cURLParse, URLParse_alloc);
  rb_define_method(cURLParse, "initialize", URLParse_init, 1);
  rb_define_method(cURLParse, "parse", URLParse_parse, 0);
}
