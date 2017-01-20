typedef struct parse_machine {
  size_t mark;
} parse_machine;

void execute(const char *buffer, size_t len, parse_machine *pm);
