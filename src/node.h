#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "util.h"

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

node_t *new_node(syntax_kind_t kind);

#endif
