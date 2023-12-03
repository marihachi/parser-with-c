#ifndef _PARSE_H
#define _PARSE_H

#include <stdint.h>
#include "list.h"
#include "scan.h"

typedef enum _syntax_kind {
  N_PROGRAM,
  N_NUMBER_LITERAL,
  N_IDENTIFIER,
  N_FUNC_DECL,
  N_VAR_DECL,
} syntax_kind_t;

typedef union _syntax {
  struct { } program;

  struct {
    int value;
  } number_literal;

  struct {
    int name_length;
    uint8_t *name_ptr;
  } identifier;
} syntax_t;

typedef struct _node {
  list_ptr_t children;
  syntax_kind_t kind;
  syntax_t syntax;
} node_t;

node_t *parse(char *input, int input_length);
node_t *parse_decls(scanner_t *s);
node_t *parse_decl(scanner_t *s);
node_t *parse_statement(scanner_t *s);
node_t *parse_expression(scanner_t *s);

node_t *new_node(syntax_kind_t kind);

#endif
