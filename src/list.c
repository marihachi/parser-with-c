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

  list_ptr_t it;
  list_cell_t *cell;

  if (*list == NULL) {
    cell = new_list_cell(item);
    *list = cell;
  } else {
    it = *list;
    while (it->next != NULL) { list_move_next(&it); }

    cell = new_list_cell(item);
    it->next = cell;
  }
}

void list_insert(list_ptr_t *list, int index, void *item) {
  if (list == NULL) THROW("FAIL: null argument in list_insert()\n");

  list_ptr_t it;
  list_cell_t *next, *cell;

  if (index == 0) {
    cell = new_list_cell(item);
    next = *list;
    *list = cell;
    cell->next = next;
  } else {
    it = *list;

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

void *list_at(list_ptr_t list, int index) {
  while (list != NULL && index > 0) {
    index--;
    list_move_next(&list);
  }
  if (index != 0 || list == NULL) THROW("FAIL: index out of range in list_at()\n");

  return list->item;
}

int list_count(list_ptr_t list) {
  int i = 0;

  while (list != NULL) {
    i++;
    list_move_next(&list);
  }

  return i;
}

void list_move_next(list_ptr_t *list) {
  if (list == NULL) THROW("FAIL: null argument in list_move_next()\n");

  if (*list != NULL) {
    *list = (*list)->next;
  }
}
