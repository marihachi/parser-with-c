#include <stdio.h>
#include "node.h"
#include "iter.h"

int main(void) {
	node_t *program, *node;

	// root
	program = new_node(N_PROGRAM);

	// child 0
	node = new_node(N_NUMBER_LITERAL);
	node->syntax.number_literal.value = 1;
	node__add_child(program, node);

	// child 1
	node = new_node(N_NUMBER_LITERAL);
	node->syntax.number_literal.value = 2;
	node__add_child(program, node);

	// print root

	printf("kind: %d\n", program->kind);
	printf("children: %d\n", node__count_child(program));

	// iterate children
	node = program->children;
	iterator_t it = get_iterator((iterable_t *)node);
	while (iterator__next(&it)) {
		node = (node_t *)it.curr;
		// print child
		printf("  child kind: %d\n", node->kind);
		if (node->kind == N_NUMBER_LITERAL) {
			printf("  value: %d\n", node->syntax.number_literal.value);
		}
	}

	return 0;
}
