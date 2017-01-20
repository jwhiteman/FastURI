#include <stdio.h>
#include "parse_machine.h"

%%{
  machine url_parse;

  action shout { printf("shouting!\n"); }

  term = "ZZ";
  msg  = "hello" %shout;

  proto = msg term;

  main := proto;
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

  %% write init;
  %% write exec;
}
