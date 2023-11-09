#ifndef _NODE_H
#define _NODE_H

// syntax

typedef enum {
	N_PROGRAM,
	N_NUMBER_LITERAL,
} syntax_kind_t;

typedef union _syntax {
	void *any;
	int number_literal;
} syntax_t;

// node

typedef struct _node {
	syntax_kind_t kind;
	syntax_t syntax;
	struct _node *children;
	struct _node *next;
} node_t;

node_t *alloc_node(syntax_kind_t kind);
void add_child(node_t *parent, node_t *child);
node_t *get_child_at(node_t *parent, int index);
int count_children(node_t *parent);

#endif
