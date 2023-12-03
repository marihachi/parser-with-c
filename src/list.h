#ifndef _LIST_H
#define _LIST_H

/**
 * Usage:
 * ```c
 * // create list
 * list_ptr_t list = NULL;
 *
 * // add item
 * list_add(&list, NULL);
 *
 * // insert item
 * list_insert(&list, 0, NULL);
 *
 * // get list length
 * length = list_count(list);
 *
 * // get item
 * item = list_at(list, 0);
 *
 * // seek list
 * while (list != NULL) {
 *   // Do anything here
 *   // *list->item
 *   list_seek_next(&list);
 * }
 * ```
*/

typedef struct _list_cell {
  struct _list_cell *next;
  void *item;
} list_cell_t;

typedef list_cell_t * list_ptr_t;

void list_add(list_ptr_t *list, void *item);
void list_insert(list_ptr_t *list, int index, void *item);
void list_seek_next(list_ptr_t *list);
void *list_at(list_ptr_t list, int index);
int list_count(list_ptr_t list);

#endif
