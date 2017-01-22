#include <stdio.h>
#include "parse_machine.h"
#include "uri_parse.h"

#define LEN(AT, FPC) (FPC - buffer - AT)
#define MARK(M,FPC) (M = (FPC) - buffer)
#define PTR_TO(FIELD) (buffer + FIELD)

%%{
  machine uri_parse;

  action mark {
    MARK(mark, fpc);
  }

  action path {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_path);
  }

  action scheme {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_scheme);
  }

  action host {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_host);
  }

  action userinfo {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_userinfo);
  }

  action port {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_port);
  }

  action query {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_query);
  }

  action fragment {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_fragment);
  }

  sub_delims    = "!" | "$" | "&" | "'" | "(" | ")" | "*" | "+" | "," | ";" | "=";
  pct_encoded   = "%" xdigit xdigit;
  unreserved    = alpha | digit | "-" | "." | "_" | "~";
  pchar         = unreserved | pct_encoded | sub_delims | ":" | "@";
  segment       = pchar+;
  segment_nz_nc = (unreserved | pct_encoded | sub_delims | "@" )+;
  segment_nz    = pchar+;
  path_rootless = segment_nz ("/" segment )*;
  path_absolute = "/" (segment_nz ( "/" segment )*)?;
  path_abempty  = ("/" segment)*;
  path_noscheme = segment_nz_nc ("/" segment)*;
  path_empty    = pchar {0};
  port          = digit* >mark %port;
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
  host          = ((IP_literal) | IPv4address | reg_name) >mark %host;
  userinfo      = (unreserved | pct_encoded | sub_delims | ":" )* >mark %userinfo;
  authority     = (userinfo "@")? host (":" port)?;
  hier_part     = (("//" authority (path_abempty >mark %path))  | (path_absolute | path_rootless | path_empty) >mark %path);
  scheme        = (alpha (alpha | digit | "+" | "-" | ".")*) >mark %scheme;
  relative_part = (("//" authority path_abempty)  | (path_absolute | path_noscheme | path_empty) >mark %path);
  query         = (pchar | "/" | "?")* >mark %query;
  fragment      = (pchar | "/" | "?" )* >mark %fragment;
  relative      = relative_part ("?" query)? ("#" fragment)?;
  absolute      = scheme ":" hier_part ("?" query)? ("#" fragment)?;
  URI           = absolute | relative;

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
