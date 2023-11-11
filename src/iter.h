#ifndef _ITER_H
#define _ITER_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _iterable {
	struct _iterable *next;
} iterable_t;

typedef struct _iterator {
	iterable_t *curr;
	iterable_t *next;
} iterator_t;

iterator_t get_iterator(iterable_t *source);
bool next_item(iterator_t *self);

#endif
