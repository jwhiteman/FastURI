#include <stdio.h>
#include "parse_machine.h"

#define LEN(AT, FPC) (FPC - buffer - pm->AT)
#define MARK(M,FPC) (pm->M = (FPC) - buffer)
#define PTR_TO(F) (buffer + pm->F)

%%{
  machine url_parse;

  action dbg {
    printf("dbg called\n");
  }

  action mark {
    printf("mark called\n");
    MARK(mark, fpc);
  }

  action uri {
    printf("URI: %s\n", PTR_TO(mark));
  }

  action scheme {
    printf("scheme\n");
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

  toplabel    = alpha | alpha (alnum | "-")* alnum;
  domainlabel = alnum | alnum (alnum | "-")* alnum;
  hostname    = (domainlabel ".")* toplabel;
  host        = hostname;
  hostport    = host;
  server      = hostport;
  authority   = server;
  net_path    = "//" authority;
  relativeURI = net_path;
  URI         = relativeURI >mark %/uri;

  main := URI;
}%%

%% write data;

void
execute(const char *buffer, size_t len, parse_machine *pm)
{
  int cs = 0;
  const char *p, *pe, *eof;

  p   = buffer;
  pe  = buffer + len;
  eof = pe;

  // printf("buffer is %s\n", buffer);
  %% write init;
  %% write exec;
}
