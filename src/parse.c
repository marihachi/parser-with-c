#include "parse.h"

node_t *parse(char *input, int input_length) {
  if (input == NULL) PANIC("FAIL: null argument in parse()\n");

  char *ptr;
  scanner_t *s;

  printf("parse\n");

  s = new_scanner(input, input_length);

  return parse_decls(s);
}

node_t *parse_decls(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decls()\n");

  node_t *program, *decl;
  list_ptr_t *decls;

  program = new_node(N_PROGRAM);
  decls = &program->children;

  while (get_kind(s) != T_EOF) {
    decl = parse_decl(s);
    if (decl == NULL) break;

    list_add(decls, decl);
  }

  return program;
}

// function or variable
node_t *parse_decl(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decl()\n");

  printf("parse_decl\n");

  if (get_kind(s) == T_EOF) {
    printf("EOF\n");
    return NULL;
  }

  // TODO
  scan_next(s);
  return new_node(N_FUNC_DECL);
}

node_t *parse_statement(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_statement()\n");

  PANIC("todo\n");
}

node_t *parse_expression(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_expression()\n");

  PANIC("todo\n");
}
