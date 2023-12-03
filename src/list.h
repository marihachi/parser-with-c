#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "util.h"

typedef struct _list_cell {
  struct _list_cell *next;
  void *item;
} list_cell_t;

typedef list_cell_t * list_ptr_t;

void list_add(list_ptr_t *list, void *item);
void list_insert(list_ptr_t *list, int index, void *item);
void *list_at(list_ptr_t list, int index);
int list_count(list_ptr_t list);
void list_seek_next(list_ptr_t *list);

#endif
