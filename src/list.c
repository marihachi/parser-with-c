#include <stdlib.h>
#include "list.h"
#include "util.h"

list_cell_t *new_list_cell(void *item) {
  list_cell_t *cell;

  cell = malloc(sizeof(list_cell_t));
  if (cell == NULL) PANIC("FAIL: malloc in new_list_cell()\n");

  cell->item = item;
  cell->next = NULL;

  return cell;
}

void list_add(list_ptr_t *list, void *item) {
  if (list == NULL) PANIC("FAIL: null argument in list_add()\n");

  if (*list == NULL) {
    *list = new_list_cell(item);
  } else {
    list_ptr_t iter = *list;

    while (iter->next != NULL) { list_seek_next(&iter); }
    iter->next = new_list_cell(item);
  }
}

void list_insert(list_ptr_t *list, int index, void *item) {
  if (list == NULL) PANIC("FAIL: null argument in list_insert()\n");

  list_cell_t *cell, *next;

  if (index == 0) {
    cell = new_list_cell(item);
    next = *list;
    *list = cell;
    cell->next = next;
  } else {
    list_ptr_t iter = *list;

    // get cell at index-1
    while (iter != NULL && index > 1) {
      index--;
      list_seek_next(&iter);
    }
    if (index > 1 || iter == NULL) PANIC("FAIL: index out of range in list_insert()\n");

    cell = new_list_cell(item);
    next = iter->next;
    iter->next = cell;
    cell->next = next;
  }
}

void list_seek_next(list_ptr_t *list) {
  if (list == NULL) PANIC("FAIL: null argument in list_seek_next()\n");

  if (*list != NULL) {
    *list = (*list)->next;
  }
}

void *list_at(list_ptr_t list, int index) {
  while (list != NULL && index > 0) {
    index--;
    list_seek_next(&list);
  }
  if (index != 0 || list == NULL) PANIC("FAIL: index out of range in list_at()\n");

  return list->item;
}

int list_count(list_ptr_t list) {
  int i = 0;

  while (list != NULL) {
    i++;
    list_seek_next(&list);
  }

  return i;
}
