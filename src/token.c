#include "token.h"

token_t *new_token(token_kind_t kind) {
  token_t *ptr;

  ptr = malloc(sizeof(token_t));
  if (ptr != NULL) {
    ptr->kind = kind;
  }
  return ptr;
}
