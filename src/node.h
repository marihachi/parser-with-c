#ifndef _NODE_H
#define _NODE_H

typedef enum {
	N_PROGRAM,
	N_NUMBER,
} node_kind_t;

typedef struct _node {
	node_kind_t kind;
	struct _node *children;
	struct _node *next;
} node_t;

node_t *alloc_node(node_kind_t kind);
void add_child(node_t *parent, node_t *child);
int count_children(node_t *parent);

#endif
