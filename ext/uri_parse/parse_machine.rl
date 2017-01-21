#include <stdio.h>
#include "parse_machine.h"
#include "uri_parse.h"

#define LEN(AT, FPC) (FPC - buffer - AT)
#define MARK(M,FPC) (M = (FPC) - buffer)
#define PTR_TO(FIELD) (buffer + FIELD)

%%{
  machine uri_parse;

  action dbg {
    printf("DBG\n");
  }

  action mark {
    MARK(mark, fpc);
  }

  action uri {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_uri);
  }

  action scheme {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_scheme);
  }

  action hier {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_hier);
  }

  action host {
    printf("host\n");
  }

  action path {
   printf("path\n");
  }

  action query {
    printf("query\n");
  }

  action fragment {
     printf("fragment\n");
  }

  action done {
    printf("done\n");
  }

  sub_delims    = "!" | "$" | "&" | "'" | "(" | ")" | "*" | "+" | "," | ";" | "=";
  pct_encoded   = "%" xdigit xdigit;
  unreserved    = alpha | digit | "-" | "." | "_" | "~";
  pchar         = unreserved | pct_encoded | sub_delims | ":" | "@";
  path_empty    = pchar {0};
  segment       = pchar+;
  segment_nz_nc = (unreserved | pct_encoded | sub_delims | "@" )+;
  segment_nz    = pchar+;
  path_rootless = segment_nz ("/" segment )*;
  path_absolute = "/" (segment_nz ( "/" segment )*)?;
  path_abempty  = ("/" segment)*;
  port          = digit*;
  reg_name      = (unreserved | pct_encoded | sub_delims)*;
  dec_octet     = digit{2};
  IPv4address   = dec_octet "." dec_octet "." dec_octet "." dec_octet;
  IPvFuture     = "v" xdigit+ "." (unreserved | sub_delims | ":" )+;
  h16           = xdigit{1,4};
  ls32          = (h16 ":" h16) | IPv4address;
  IPv6address   =                             (h16 ":"){6} ls32
                  |                      "::" (h16 ":"){5} ls32
                  | (              h16)? "::" (h16 ":"){4} ls32
                  | ((h16 ":")?    h16)? "::" (h16 ":"){3} ls32
                  | ((h16 ":"){,2} h16)? "::" (h16 ":"){2} ls32
                  | ((h16 ":"){,3} h16)? "::"  h16 ":"     ls32
                  | ((h16 ":"){,4} h16)? "::"              ls32
                  | ((h16 ":"){,5} h16)? "::"               h16
                  | ((h16 ":"){,6} h16)? "::";
  IP_literal    = "[" (IPv6address | IPvFuture) "]";
  host          = (IP_literal) | IPv4address | reg_name;
  userinfo      = (unreserved | pct_encoded | sub_delims | ":" )*;
  authority     = (userinfo "@")? host (":" port)?;
  hier_part     = (("//" authority path_abempty)  | path_absolute | path_rootless | path_empty) >mark %hier;
  scheme        = (alpha (alpha | digit | "+" | "-" | ".")*) >mark %scheme;
  URI           = scheme ":" hier_part @/done;

  main := URI;
}%%

%% write data;

void
execute(void *hash, const char *buffer, size_t len)
{
  size_t mark = 0;
  int cs = 0;
  const char *p, *pe, *eof;

  p   = buffer;
  pe  = buffer + len;
  eof = pe;

  %% write init;
  %% write exec;
}
