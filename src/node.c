#include "node.h"

node_t *new_node(syntax_kind_t kind) {
  node_t *node;

  node = malloc(sizeof(node_t));

  if (node == NULL) {
    printf("FAIL: malloc in new_node()\n");
    while (1) {}
  }

  node->kind = kind;
  node->children = NULL;
  node->next = NULL;

  return node;
}

void add_child_node(node_t *self, node_t *child) {
  iterator_t it;
  node_t *node;

  if (self->children == NULL) {
    self->children = child;
  } else {
    it = new_iter(self->children);

    while (next_item(&it)) { }
    node = get_item(&it);

    node->next = child;
  }
}

void insert_child_node(node_t *self, int index, node_t *child) {
  iterator_t it;
  node_t *node;

  it = new_iter(self->children);

  while (next_item(&it) && index > 0) {
    index--;
  }

  if (index != 0) {
    printf("FAIL: index out of range in insert_child_node()\n");
    while (1) {}
  }

  node = get_item(&it);
  child->next = node->next;
  node->next = child;
}

node_t *get_child_node_at(node_t *self, int index) {
  iterator_t it;

  it = new_iter(self->children);

  while (next_item(&it) && index > 0) {
    index--;
  }

  if (index != 0) {
    printf("FAIL: index out of range in get_child_node_at()\n");
    while (1) {}
  }

  return get_item(&it);
}

int count_children(node_t *self) {
  iterator_t it;
  int i;

  it = new_iter(self->children);

  i = 0;
  while (next_item(&it)) {
    i++;
  }

  return i;
}

iterator_t new_iter(node_t *source) {
  iterator_t it;
  it.curr = NULL;
  it.next = source;
  return it;
}

/** @returns successful */
bool next_item(iterator_t *self) {
  if (self->next == NULL) {
    // next item not exists
    return false;
  }
  self->curr = self->next;
  self->next = self->curr->next;
  return true;
}

node_t *get_item(iterator_t *self) {
  return self->curr;
}
