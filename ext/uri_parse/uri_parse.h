#ifndef URI_PARSE_H
#define URI_PARSE_H 1

#include "ruby.h"

VALUE URIParse_set(void *upi, const char *sptr, size_t len, unsigned long k);

#define id_ivar_uri rb_intern("@uri")
#define id_ivar_parsed_results rb_intern("@parsed_results")
#define id_uri rb_intern("uri")

#endif /* URI_PARSE_H */