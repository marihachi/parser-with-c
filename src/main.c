#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(void) {
	node_t *node;

	node = alloc_node(N_PROGRAM);
	add_child(node, alloc_node(N_NUMBER));
	add_child(node, alloc_node(N_NUMBER));

	printf("kind: %d\n", node->kind);
	printf("children: %d\n", count_children(node));
	node = node->children;
	while (node != NULL) {
		printf("  child kind: %d\n", node->kind);
		node = node->next;
	}

	return 0;
}
