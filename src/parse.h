#ifndef _PARSE_H
#define _PARSE_H

#include <stdint.h>
#include "list.h"
#include "scanner.h"

typedef enum syntax_kind {
  N_PROGRAM,
  N_NUMBER_LITERAL,
  N_IDENTIFIER,
  N_FUNC_DECL,
  N_VAR_DECL,
} syntax_kind_t;

typedef struct node {
  list_ptr_t children;
  syntax_kind_t kind;
  int name_length;
  char *name_ptr;

  // additional info
  union {
    struct {
      int string_length;
      char *string_ptr;
    } string_value;

    int number_value;
  };
} node_t;

node_t *parse(char *input, int input_length);

#endif
