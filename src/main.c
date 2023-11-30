#include <stdio.h>
#include "node.h"
#include "scan.h"

int main(void) {
  node_t *program, *node, *children;

  // root
  program = new_node(N_PROGRAM);
  children = program->children;

  // child 0
  node = new_node(N_NUMBER_LITERAL);
  node->syntax.number_literal.value = 1;
  list_add(&children, node);

  // child 1
  node = new_node(N_NUMBER_LITERAL);
  node->syntax.number_literal.value = 2;
  list_add(&children, node);

  // print root

  printf("kind: %d\n", program->kind);
  printf("children: %d\n", list_count(&children));

  // iterate children
  node = children;
  while (node != NULL) {
    // print child
    printf("  child kind: %d\n", node->kind);
    if (node->kind == N_NUMBER_LITERAL) {
      printf("  value: %d\n", node->syntax.number_literal.value);
    }
    list_move_next(&node);
  }

  return 0;
}
