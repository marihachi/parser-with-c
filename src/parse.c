#include <stdlib.h>
#include <stdbool.h>
#include "parse.h"
#include "util.h"
#include "list.h"

node_t *parse(char *input, int input_length) {
  if (input == NULL) PANIC("FAIL: null argument in parse()\n");

  scanner_t *s;

  s = new_scanner(input, input_length);

  bool error = false;
  node_t *node = parse_decls(s, &error);
  if (error) return NULL;

  return node;
}

node_t *parse_decls(scanner_t *s, bool *error) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decls()\n");

  node_t *program, *decl;

  program = new_node(N_PROGRAM);

  while (get_kind(s) != T_EOF) {
    decl = parse_decl(s, error);
    if (*error) return NULL;

    list_add(&(program->children), decl);
  }

  return program;
}

// function or variable
node_t *parse_decl(scanner_t *s, bool *error) {
  if (s == NULL) PANIC("FAIL: null argument in parse_decl()\n");

  token_t *token;

  printf("T_IDENTIFIER\n");
  if (!expect_token(s, T_IDENTIFIER)) {
    *error = true;
    return NULL;
  }
  token = get_token(s);
  if (!scan_next(s)) {
    *error = true;
    return NULL;
  }

  printf("T_IDENTIFIER\n");
  if (!expect_token(s, T_IDENTIFIER)) {
    *error = true;
    return NULL;
  }
  token = get_token(s);
  if (!scan_next(s)) {
    *error = true;
    return NULL;
  }

  printf("T_OPEN_PAREN\n");
  if (!scan_next_with(s, T_OPEN_PAREN)) {
    *error = true;
    return NULL;
  }
  printf("T_CLOSE_PAREN\n");
  if (!scan_next_with(s, T_CLOSE_PAREN)) {
    *error = true;
    return NULL;
  }

  printf("T_OPEN_BRACE\n");
  if (!scan_next_with(s, T_OPEN_BRACE)) {
    *error = true;
    return NULL;
  }
  printf("T_CLOSE_BRACE\n");
  if (!scan_next_with(s, T_CLOSE_BRACE)) {
    *error = true;
    return NULL;
  }

  return new_node(N_FUNC_DECL);
}

node_t *parse_statement(scanner_t *s, bool *error) {
  if (s == NULL) PANIC("FAIL: null argument in parse_statement()\n");

  PANIC("todo\n");
}

node_t *parse_expression(scanner_t *s, bool *error) {
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
