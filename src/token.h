#ifndef _TOKEN_H
#define _TOKEN_H

#include <stdlib.h>

typedef enum _token_kind {
  T_EOF,
  T_IDENTIFIER,
  T_NUMBER_LITERAL,
} token_kind_t;

typedef struct _token {
  token_kind_t kind : 8;
  int value_length : 8;
  int PADDING_1 : 16;
  char value[32];
} token_t;

token_t *new_token(token_kind_t kind);

#endif
