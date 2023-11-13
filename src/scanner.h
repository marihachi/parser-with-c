#ifndef _SCANNER_H
#define _SCANNER_H

#include <stdlib.h>
#include <stdbool.h>
#include "token.h"

typedef struct _scanner {
  char *source;
  int source_length;
  int index;
  int line;
  int column;
  token_t *token;
} scanner_t;

scanner_t *new_scanner(char *source, int source_length);
token_t *get_token(scanner_t *self);
token_kind_t get_kind(scanner_t *self);
bool scan_next(scanner_t *self);
bool expect_token(scanner_t *self, token_kind_t kind);
bool scan_next_with(scanner_t *self, token_kind_t kind);

#endif
