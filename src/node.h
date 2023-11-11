#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>

// syntax

typedef enum _syntax_kind {
	N_PROGRAM,
	N_NUMBER_LITERAL,
} syntax_kind_t;

typedef union _syntax {
	struct {
		// dummy
	} program;

	struct {
		int value;
	} number_literal;
} syntax_t;

// node

typedef struct _node {
	// implement iterator_t
	struct _node *next;

	syntax_kind_t kind;
	syntax_t syntax;
	struct _node *children;
} node_t;

node_t *new_node(syntax_kind_t kind);
void add_child_node(node_t *self, node_t *child);
void insert_child_node(node_t *self, int index, node_t *child);
node_t *get_child_node_at(node_t *self, int index);
int count_child_node(node_t *self);

#endif
