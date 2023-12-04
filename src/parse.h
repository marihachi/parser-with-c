#ifndef _PARSE_H
#define _PARSE_H

#include <stdint.h>
#include "list.h"
#include "scan.h"

typedef enum syntax_kind {
  N_PROGRAM,
  N_NUMBER_LITERAL,
  N_IDENTIFIER,
  N_FUNC_DECL,
  N_VAR_DECL,
} syntax_kind_t;

typedef union syntax {
  struct { } program;

  struct {
    int value;
  } number_literal;

  struct {
    int name_length;
    uint8_t *name_ptr;
  } identifier;
} syntax_t;

typedef struct node {
  list_ptr_t children;
  syntax_kind_t kind;
  syntax_t syntax;
} node_t;

node_t *parse(char *input, int input_length);

#endif
