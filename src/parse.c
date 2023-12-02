#include "parse.h"

node_t *parse(char *input, int input_length) {
  if (input == NULL) { printf("FAIL: null argument in parse()\n"); exit(EXIT_FAILURE); }

  scanner_t *s = new_scanner(input, input_length);

  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_decls(scanner_t *s) {
  if (s == NULL) { printf("FAIL: null argument in parse_decls()\n"); exit(EXIT_FAILURE); }

  node_t *node = new_node(N_PROGRAM);
  node_t *decl = NULL;
  while (get_kind(s) != T_EOF) {
    decl = parse_decl(s);
    if (decl == NULL) break;
    list_add(&(node->children), decl);
  }
  return node;
}

// function or variable
node_t *parse_decl(scanner_t *s) {
  if (s == NULL) { printf("FAIL: null argument in parse_decl()\n"); exit(EXIT_FAILURE); }

  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_statement(scanner_t *s) {
  if (s == NULL) { printf("FAIL: null argument in parse_statement()\n"); exit(EXIT_FAILURE); }

  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_expression(scanner_t *s) {
  if (s == NULL) { printf("FAIL: null argument in parse_expression()\n"); exit(EXIT_FAILURE); }

  printf("todo\n");
  exit(EXIT_FAILURE);
}
