#include "iter.h"

iterator_t get_iterator(iterable_t *source) {
	iterator_t it;
	it.curr = NULL;
	it.next = source;
	return it;
}

/** @returns successful */
bool iterator__next(iterator_t *self) {
	self->curr = self->next;
	if (self->curr == NULL) {
		// next item not exists
		return false;
	}
	self->next = self->next->next;
	return true;
}
