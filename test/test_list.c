#include "test.h"
#include "../src/node.h"

int test_list(void) {
  node_t *list1;
  node_t *list2;

  list1 = NULL;
  OK(list_count(&list1) == 0);

  list_add(&list1, new_node(N_NUMBER_LITERAL));
  OK(list_count(&list1) == 1);
  OK(list_at(&list1, 0) != NULL);

  list2 = list1;
  list_move_next(&list2);
  OK(list_count(&list2) == 0);
  OK(list_count(&list1) == 1);

  return TEST_PASS;
}
