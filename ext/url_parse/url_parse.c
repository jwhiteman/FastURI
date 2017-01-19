#include "url_parse.h"

VALUE rb_cURLParse;

void
Init_url_parse(void)
{
  rb_cURLParse = rb_define_class("URLParse", rb_cObject);
}
