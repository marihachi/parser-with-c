#include "parse.h"

node_t *parse(char *input, int input_length) {
  scanner_t *s = new_scanner(input, input_length);

  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_decls(scanner_t *s) {
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
  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_statement(scanner_t *s) {
  printf("todo\n");
  exit(EXIT_FAILURE);
}

node_t *parse_expression(scanner_t *s) {
  printf("todo\n");
  exit(EXIT_FAILURE);
}
