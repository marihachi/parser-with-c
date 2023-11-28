#ifndef _SCAN_H
#define _SCAN_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum _token_kind {
  // Special
  T_EOF = 0x00,
  T_IDENTIFIER,
  T_NUMBER_LITERAL,
  T_CHAR_LITERAL,
  T_STRING_LITERAL,

  // Symbol
  T_EXCL = 0x40, // "!"
  T_PERCENT, // "%"
  T_AND1, // "&"
  T_AND2, // "&&"
  T_OPEN_PAREN, // "("
  T_CLOSE_PAREN, // ")"
  T_ASTER, // "*"
  T_PLUS, // "+"
  T_COMMA, // ","
  T_MINUS, // "-"
  T_DOT, // "."
  T_SLASH, // "/"
  T_COLON, // ":"
  T_SEMI, // ";"
  T_LT, // "<"
  T_LTE, // "<="
  T_EQ1, // "="
  T_EQ2, // "=="
  T_GT, // ">"
  T_GTE, // ">="
  T_QUEST, // "?"
  T_OPEN_BRACKET, // "["
  T_CLOSE_BRACKET, // "]"
  T_HAT, // "^"
  T_OPEN_BRACE, // "{"
  T_OR1, // "|"
  T_OR2, // "||"
  T_CLOSE_BRACE, // "}"
  T_TILDE, // "~"

  // Keyword
  T_IF = 0x80,
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
