#include <stdio.h>
#include "../src/node.h"

#define TEST_CASE_REQUIRED 100
#define INVALID_TEST_CASE 101
#define TEST_CASE_NOT_EXISTS 102

#define TEST_PASS 0
#define TEST_FAIL 1
#define OK(expr) if (!(expr)) return TEST_FAIL

int test_list() {
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

int main(int argc, char* argv[]) {
  int test_case, count;

  if (argc < 2) return TEST_CASE_REQUIRED;
  count = sscanf(argv[1], "%d", &test_case);
  if (count != 1) return INVALID_TEST_CASE;

  switch (test_case) {
    case 1: {
      return test_list();
    }
  }

  return TEST_CASE_NOT_EXISTS;
}
