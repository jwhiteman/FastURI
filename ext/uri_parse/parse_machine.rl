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

  action uri {
    URIParse_set(hash, PTR_TO(mark), LEN(mark, fpc), id_uri);
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

  IPv4address = digit+ "." digit+ "." digit+ "." digit+;
  toplabel    = alpha | alpha (alnum | "-")* alnum;
  domainlabel = alnum | alnum (alnum | "-")* alnum;
  hostname    = (domainlabel ".")* toplabel (".")?;
  host        = hostname | IPv4address;
  hostport    = host;
  server      = hostport;
  authority   = server;
  net_path    = "//" authority;
  relativeURI = net_path;
  URI         = relativeURI >mark %uri;

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
