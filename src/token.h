#ifndef _TOKEN_H
#define _TOKEN_H

#include <stdlib.h>

typedef enum _token_kind {
  T_EOF,
  T_IDENTIFIER,
  T_NUMBER_LITERAL,
} token_kind_t;

typedef struct _token {
  token_kind_t kind;
  char *value;
  int value_length;
} token_t;

token_t *new_token(token_kind_t kind);

#endif
