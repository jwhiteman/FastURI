#ifndef FAST_URI_H
#define FAST_URI_H 1

#include "ruby.h"

void FastURI_set(void *h, const char *sptr, size_t len, unsigned long k);

#define id_userinfo rb_intern("userinfo")
#define id_host rb_intern("host")
#define id_path rb_intern("path")
#define id_scheme rb_intern("scheme")
#define id_port rb_intern("port")
#define id_query rb_intern("query")
#define id_fragment rb_intern("fragment")

#endif /* FAST_URI_H */
