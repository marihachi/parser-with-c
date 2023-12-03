#ifndef _LIST_H
#define _LIST_H

/**
 * Create list:
 * ```c
 * list_ptr_t list = NULL;
 * ```
 * 
 * Seek list:
 * ```c
 * // list_ptr_t list;
 * // int *item;
 * 
 * while (list != NULL) {
 *   item = list_get_current(list);
 *   // Do anything here
 *   list_seek_next(&list);
 * }
 * ```
*/

typedef struct _list_cell {
  struct _list_cell *next;
  void *item;
} list_cell_t;

typedef list_cell_t * list_ptr_t;

/**
 * Add item
 * This function changes the list.
*/
void list_add(list_ptr_t *list, void *item);

/**
 * Insert item
 * This function changes the list.
*/
void list_insert(list_ptr_t *list, int index, void *item);

/**
 * Seek next position
 * This function changes the list.
*/
void list_seek_next(list_ptr_t *list);

/**
 * Get item
 * This function do not changes the list.
*/
void *list_get_current(list_ptr_t list);

/**
 * Get item
 * This function do not changes the list.
*/
void *list_at(list_ptr_t list, int index);

/**
 * Get length of the list
 * This function do not changes the list.
*/
int list_count(list_ptr_t list);

#endif
