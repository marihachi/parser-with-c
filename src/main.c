#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(void) {
	node_t *program, *node;

	// root
	program = alloc_node(N_PROGRAM);

	// child 0
	node = alloc_node(N_NUMBER_LITERAL);
	node->syntax.number_literal = 1;
	add_child(program, node);

	// child 1
	node = alloc_node(N_NUMBER_LITERAL);
	node->syntax.number_literal = 2;
	add_child(program, node);

	// print root

	printf("kind: %d\n", program->kind);
	printf("children: %d\n", count_children(program));

	// iterate children
	node = program->children;
	while (node != NULL) {
		// print child
		printf("  child kind: %d\n", node->kind);
		if (node->kind == N_NUMBER_LITERAL) {
			printf("  value: %d\n", node->syntax.number_literal);
		}
		node = node->next;
	}

	return 0;
}
