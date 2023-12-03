#include "list.h"

list_cell_t *new_list_cell(void *item) {
  list_cell_t *cell;

  cell = malloc(sizeof(list_cell_t));
  if (cell == NULL) THROW("FAIL: malloc in new_list_cell()\n");

  cell->item = item;
  cell->next = NULL;

  return cell;
}

void list_add(list_ptr_t *list, void *item) {
  if (list == NULL) THROW("FAIL: null argument in list_add()\n");

  list_ptr_t it = *list;
  list_cell_t *next, *cell;

  if (*list == NULL) {
    cell = new_list_cell(item);
    *list = cell;
  } else {
    while (it->next != NULL) { list_move_next(&it); }

    cell = new_list_cell(item);
    it->next = cell;
  }
}

void list_insert(list_ptr_t *list, int index, void *item) {
  if (list == NULL) THROW("FAIL: null argument in list_insert()\n");

  list_ptr_t it = *list;
  list_cell_t *next, *cell;

  if (index == 0) {
    // if (*list == NULL) {
    //   cell = new_list_cell(item);
    //   *list = cell;
    // } else {
    //   cell = new_list_cell(item);
    //   next = *list;
    //   *list = cell;
    //   (*list)->next = next;
    // }
    cell = new_list_cell(item);
    next = *list;
    *list = cell;
    cell->next = next;
  } else {
    // get cell at index-1
    while (it != NULL && index > 1) {
      index--;
      list_move_next(&it);
    }
    if (index > 1 || it == NULL) THROW("FAIL: index out of range in list_insert()\n");

    cell = new_list_cell(item);
    next = it->next;
    it->next = cell;
    cell->next = next;
  }
}

void *list_at(list_ptr_t *list, int index) {
  if (list == NULL) THROW("FAIL: null argument in list_at()\n");

  list_ptr_t it = *list;

  while (it != NULL && index > 0) {
    index--;
    list_move_next(&it);
  }
  if (index != 0 || it == NULL) THROW("FAIL: index out of range in list_at()\n");

  return it->item;
}

int list_count(list_ptr_t *list) {
  if (list == NULL) THROW("FAIL: null argument in list_count()\n");

  int i = 0;
  list_ptr_t it = *list;

  while (it != NULL) {
    i++;
    list_move_next(&it);
  }

  return i;
}

void list_move_next(list_ptr_t *list) {
  if (list == NULL) THROW("FAIL: null argument in list_move_next()\n");

  if (*list != NULL) {
    *list = (*list)->next;
  }
}
