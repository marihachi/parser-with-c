#ifndef _SCAN_H
#define _SCAN_H

#include <stdint.h>
#include <stdbool.h>

typedef enum _token_kind {
  // Special
  T_EOF = 0x00,
  T_IDENTIFIER,
  T_NUMBER_LITERAL,
  T_STRING_LITERAL,
  T_CHAR_LITERAL,

  // Symbol
  T_OPEN_PAREN = 0x40, // "("
  T_CLOSE_PAREN, // ")"
  T_OPEN_BRACKET, // "["
  T_CLOSE_BRACKET, // "]"
  T_OPEN_BRACE, // "{"
  T_CLOSE_BRACE, // "}"
  T_SEMI, // ";"
  T_COMMA, // ","
  T_PLUS, // "+"
  T_MINUS, // "-"
  T_ASTER, // "*"
  T_SLASH, // "/"
  T_PERCENT, // "%"
  T_EQ1, // "="
  T_EQ2, // "=="
  T_LT, // "<"
  T_LTE, // "<="
  T_GT, // ">"
  T_GTE, // ">="
  T_AND1, // "&"
  T_AND2, // "&&"
  T_OR1, // "|"
  T_OR2, // "||"
  T_EXCL, // "!"
  T_DOT, // "."
  T_ARROW, // "->"
  T_HAT, // "^"
  T_TILDE, // "~"
  T_QUEST, // "?"
  T_COLON, // ":"

  // Keyword
  T_IF = 0x80,
} token_kind_t;

typedef struct _token {
  token_kind_t kind;
  int value_length;
  uint8_t *value_ptr;
} token_t;

typedef struct _scanner {
  int index;
  int line;
  int column;
  int source_length;
  char *source;
  token_t *token;
} scanner_t;

scanner_t *new_scanner(char *source, int source_length);
token_t *get_token(scanner_t *self);
token_kind_t get_kind(scanner_t *self);
bool scan_next(scanner_t *self);
bool expect_token(scanner_t *self, token_kind_t kind);
bool scan_next_with(scanner_t *self, token_kind_t kind);

#endif
