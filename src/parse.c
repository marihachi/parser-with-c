#include <stdlib.h>
#include <stdbool.h>
#include "parse.h"
#include "util.h"
#include "list.h"

bool parse_decls(scanner_t *s, node_t **result);
bool parse_decl(scanner_t *s, node_t **result);
bool parse_statement(scanner_t *s, node_t **result);
bool parse_expression(scanner_t *s, node_t **result);
node_t *new_node(syntax_kind_t kind);

node_t *parse(char *input, int input_length) {
  if (input == NULL) PANIC("FAIL: null argument in parse()\n");

  scanner_t *s;

  s = new_scanner(input, input_length);
  if (!scan_token(s)) return NULL;

  node_t *node = NULL;
  if (!parse_decls(s, &node)) return NULL;

  return node;
}

bool parse_decls(scanner_t *s, node_t **result) {
  node_t *program, *decl;

  if (s == NULL) PANIC("FAIL: null argument in parse_decls()\n");
  *result = NULL;

  program = new_node(N_PROGRAM);

  while (get_kind(s) != T_EOF) {
    if (!parse_decl(s, &decl)) return false;
    list_add(&(program->children), decl);
  }

  *result = program;
  return true;
}

// function or variable
bool parse_decl(scanner_t *s, node_t **result) {
  token_t *token;
  char *name_ptr, *ty_ptr;
  int name_length, ty_length;

  if (s == NULL) PANIC("FAIL: null argument in parse_decl()\n");
  *result = NULL;

  if (!expect_token(s, T_IDENTIFIER)) return false;
  token = get_token(s);
  ty_ptr = token->value_ptr;
  ty_length = token->value_length;
  if (!scan_next(s)) return false;

  if (!expect_token(s, T_IDENTIFIER)) return false;
  token = get_token(s);
  name_ptr = token->value_ptr;
  name_length = token->value_length;
  if (!scan_next(s)) return false;

  if (get_kind(s) == T_SEMI) {
    scan_next(s);
    *result = new_node(N_VAR_DECL);
    (*result)->name_ptr = name_ptr;
    (*result)->name_length = name_length;
    return true;
  }

  if (!scan_next_with(s, T_OPEN_PAREN)) return false;
  if (!scan_next_with(s, T_CLOSE_PAREN)) return false;

  if (get_kind(s) == T_SEMI) {
    scan_next(s);
    *result = new_node(N_FUNC_DECL);
    (*result)->name_ptr = name_ptr;
    (*result)->name_length = name_length;
    return true;
  }

  if (!scan_next_with(s, T_OPEN_BRACE)) return false;
  if (!scan_next_with(s, T_CLOSE_BRACE)) return false;

  *result = new_node(N_FUNC_DECL);
  (*result)->name_ptr = name_ptr;
  (*result)->name_length = name_length;
  return true;
}

bool parse_statement(scanner_t *s, node_t **result) {
  if (s == NULL) PANIC("FAIL: null argument in parse_statement()\n");
  *result = NULL;

  PANIC("todo\n");
}

bool parse_expression(scanner_t *s, node_t **result) {
  if (s == NULL) PANIC("FAIL: null argument in parse_expression()\n");
  *result = NULL;

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
