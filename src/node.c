#include "node.h"

node_t *new_node(syntax_kind_t kind) {
  node_t *node;
  node = malloc(sizeof(node_t));
  if (node == NULL) PANIC("FAIL: malloc in new_node()\n");

  node->kind = kind;
  node->children = NULL;
  return node;
}
