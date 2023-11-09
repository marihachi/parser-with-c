#include <stdlib.h>
#include "node.h"

node_t *alloc_node(node_kind_t kind) {
	node_t *ptr;
	ptr = malloc(sizeof(node_t));
	if (ptr != NULL) {
		ptr->kind = kind;
	}
	return ptr;
}

void add_child(node_t *parent, node_t *child) {
	node_t * node;
	if (parent->children == NULL) {
		parent->children = child;
	} else {
		node = parent->children;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = child;
	}
}

int count_children(node_t *parent) {
	int i;
	node_t *node;
	i = 0;
	node = parent->children;
	while (node != NULL) {
		i++;
		node = node->next;
	}
	return i;
}
