#include <stdlib.h>
#include "parse.h"
#include "util.h"
#include "list.h"

node_t *parse(char *input, int input_length) {
  if (input == NULL) PANIC("FAIL: null argument in parse()\n");

  scanner_t *s;

  s = new_scanner(input, input_length);

  return parse_decls(s);
}

node_t *parse_decls(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decls()\n");

  node_t *program, *decl;

  program = new_node(N_PROGRAM);

  while (get_kind(s) != T_EOF) {
    decl = parse_decl(s);
    if (decl == NULL) break;

    list_add(&(program->children), decl);
  }

  return program;
}

// function or variable
node_t *parse_decl(scanner_t *s) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decl()\n");

  if (get_kind(s) == T_EOF) {
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

node_t *new_node(syntax_kind_t kind) {
  node_t *node;

  node = malloc(sizeof(node_t));
  if (node == NULL) PANIC("FAIL: malloc in new_node()\n");

  node->kind = kind;
  node->children = NULL;

  return node;
}
