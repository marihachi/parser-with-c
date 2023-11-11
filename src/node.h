#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>
#include <stdbool.h>

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

typedef struct _node {
	syntax_kind_t kind;
	syntax_t syntax;
	struct _node *next;
	struct _node *children;
} node_t;

// iterator
typedef struct _iterator {
	node_t *curr;
	node_t *next;
} iterator_t;

node_t *new_node(syntax_kind_t kind);
void add_child_node(node_t *self, node_t *child);
void insert_child_node(node_t *self, int index, node_t *child);
node_t *get_child_node_at(node_t *self, int index);
int count_child_node(node_t *self);

// iterator
iterator_t create_iterator(node_t *source);
/** @returns successful */
bool next_iterator_item(iterator_t *self);
node_t *get_iterator_item(iterator_t *self);

#endif
