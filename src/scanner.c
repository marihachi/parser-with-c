#include "scanner.h"

static bool is_eof(scanner_t *self) {
	return (self->index >= self->source_length);
}

static char get_char(scanner_t *self) {
	if (is_eof(self)) {
		// error
		abort();
		return 0;
	}
	return *(self->source + self->index);
}

static bool next_index(scanner_t *self) {
	if (is_eof(self)) {
		return false;
	}
	self->index = self->index + 1;
	return true;
}

static bool scan_number(scanner_t *self) {
	get_char(self);
	// TODO
	abort();
}

static bool scan_word(scanner_t *self) {
	// TODO
	abort();
}

scanner_t *new_scanner(char *source, int source_length) {
	scanner_t *ptr;
	ptr = malloc(sizeof(scanner_t));

	if (ptr != NULL) {
		ptr->source = source;
		ptr->source_length = source_length;
		ptr->index = 0;
		ptr->line = 0;
		ptr->column = 0;
		ptr->token = NULL;
	}

	return ptr;
}

bool scan_current(scanner_t *self) {
	char ch;

	if (self->index >= self->source_length) {
		self->token = new_token(T_EOF);
		return true;
	}

	ch = get_char(self);

	switch (ch) {

	}

	if (scan_number(self)) {
		return true;
	}
	if (scan_word(self)) {
		return true;
	}
	return false;
}

void scan_next(scanner_t *self) {
	// TODO
	abort();
}

bool scan_next_with(scanner_t *self, token_kind_t kind) {
	// TODO
	abort();
}

bool expect_token(scanner_t *self, token_kind_t kind) {
	// TODO
	abort();
}

token_kind_t get_kind(scanner_t *self) {
	// TODO
	abort();
}

token_t *get_token(scanner_t *self) {
	// TODO
	abort();
}
