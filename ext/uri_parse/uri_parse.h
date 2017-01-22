#ifndef URI_PARSE_H
#define URI_PARSE_H 1

#include "ruby.h"

void URIParse_set(void *h, const char *sptr, size_t len, unsigned long k);

#define id_userinfo rb_intern("userinfo")
#define id_host rb_intern("host")
#define id_path rb_intern("path")
#define id_scheme rb_intern("scheme")
#define id_port rb_intern("port")
#define id_query rb_intern("query")
#define id_fragment rb_intern("fragment")

#endif /* URI_PARSE_H */
