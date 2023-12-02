#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
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
  struct _node *next;
  struct _node *children;
  syntax_kind_t kind;
  syntax_t syntax;
} node_t;

node_t *new_node(syntax_kind_t kind);

// node list
void list_add(node_t **list, node_t *item);
void list_insert(node_t **list, int index, node_t *item);
node_t *list_at(node_t **list, int index);
int list_count(node_t **list);
void list_move_next(node_t **list);

#endif
