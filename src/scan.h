#ifndef _SCAN_H
#define _SCAN_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum _token_kind {
  T_EOF,
  T_IDENTIFIER,
  T_NUMBER_LITERAL,
  T_OPEN_PAREN, // "("
  T_CLOSE_PAREN, // ")"
  T_OPEN_BRACE, // "{"
  T_CLOSE_BRACE, // "{"
  T_OPEN_BRACKET, // "["
  T_CLOSE_BRACKET, // "]"
} token_kind_t;

typedef struct _token {
  token_kind_t kind;
  int value_length;
  uint8_t *value_ptr;
} token_t;

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
