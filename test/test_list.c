#include "test.h"
#include "../src/list.h"

int test_list_add(void) {
  list_ptr_t list1 = NULL;
  int value1 = 1;
  int value2 = 2;
  int *value_ptr;

  OK(list_count(&list1) == 0);

  // add to empty list
  list_add(&list1, &value1);

  OK(list_count(&list1) == 1);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);

  // add to tail
  list_add(&list1, &value2);

  OK(list_count(&list1) == 2);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value2);

  return TEST_PASS;
}

int test_list_insert(void) {
  list_ptr_t list1 = NULL;
  int *value_ptr;
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;
  int value4 = 4;
  int value5 = 5;

  OK(list_count(&list1) == 0);

  // insert to empty list
  list_insert(&list1, 0, &value1);

  // 1

  OK(list_count(&list1) == 1);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);

  list_add(&list1, &value2);

  // 1 2

  OK(list_count(&list1) == 2);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value2);

  // insert to head
  list_insert(&list1, 0, &value3);

  // 3 1 2

  OK(list_count(&list1) == 3);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value3);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 2);
  OK(value_ptr == &value2);

  // insert to middle
  list_insert(&list1, 2, &value4);

  // 3 1 4 2

  OK(list_count(&list1) == 4);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value3);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 2);
  OK(value_ptr == &value4);
  value_ptr = list_at(&list1, 3);
  OK(value_ptr == &value2);

  // insert to tail
  list_insert(&list1, 4, &value5);

  // 3 1 4 2 5

  OK(list_count(&list1) == 5);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value3);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 2);
  OK(value_ptr == &value4);
  value_ptr = list_at(&list1, 3);
  OK(value_ptr == &value2);
  value_ptr = list_at(&list1, 4);
  OK(value_ptr == &value5);

  return TEST_PASS;
}

int test_list_seek(void) {
  list_ptr_t list1 = NULL;
  list_ptr_t list2 = NULL;
  int *value_ptr;
  int value1 = 1;
  int value2 = 2;

  list_add(&list1, &value1);
  list_add(&list1, &value2);
  list2 = list1;

  // NOTE: シークすることで同じ要素を指してる他のリストに影響を与えないか

  OK(list_count(&list1) == 2);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value2);

  OK(list_count(&list2) == 2);
  value_ptr = list_at(&list2, 0);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list2, 1);
  OK(value_ptr == &value2);

  list_move_next(&list2);

  OK(list_count(&list1) == 2);
  value_ptr = list_at(&list1, 0);
  OK(value_ptr == &value1);
  value_ptr = list_at(&list1, 1);
  OK(value_ptr == &value2);

  OK(list_count(&list2) == 1);
  value_ptr = list_at(&list2, 0);
  OK(value_ptr == &value2);

  return TEST_PASS;
}

int test_list(void) {
  OK(test_list_add() == TEST_PASS);
  OK(test_list_insert() == TEST_PASS);
  OK(test_list_seek() == TEST_PASS);

  return TEST_PASS;
}
