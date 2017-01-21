#ifndef URI_PARSE_H
#define URI_PARSE_H 1

#include "ruby.h"

void URIParse_set(void *h, const char *sptr, size_t len, unsigned long k);

#define id_uri rb_intern("uri")

#endif /* URI_PARSE_H */
