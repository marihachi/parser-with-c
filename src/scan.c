#include <stdlib.h>
#include <string.h>
#include "scan.h"
#include "util.h"

static bool scan_word(scanner_t *self);
static char get_char(scanner_t *self);
static bool is_eof(scanner_t *self);
static token_t *new_token(token_kind_t kind);

scanner_t *new_scanner(char *source, int source_length) {
  if (source == NULL) PANIC("FAIL: null argument in new_scanner()\n");

  scanner_t *ptr;
  ptr = malloc(sizeof(scanner_t));

  if (ptr == NULL) PANIC("FAIL: malloc in new_scanner()\n");

  ptr->source = source;
  ptr->source_length = source_length;
  ptr->index = 0;
  ptr->line = 0;
  ptr->column = 0;
  ptr->token = NULL;

  return ptr;
}

token_t *get_token(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in get_token()\n");

  return self->token;
}

token_kind_t get_kind(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in get_kind()\n");

  token_t *token = get_token(self);
  if (token == NULL) PANIC("FAIL: get token in get_kind()\n");

  return token->kind;
}

bool scan_next(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in scan_next()\n");

  if (get_kind(self) == T_EOF) {
    return true;
  }

  return scan_token(self);
}

bool expect_token(scanner_t *self, token_kind_t kind) {
  if (self == NULL) PANIC("FAIL: null argument in expect_token()\n");

  if (get_kind(self) != kind) {
    printf("SyntaxError: unexpected token. expected %s, actual %s\n", get_token_name(kind), get_token_name(get_kind(self)));
    return false;
  }

  return true;
}

bool scan_next_with(scanner_t *self, token_kind_t kind) {
  if (self == NULL) PANIC("FAIL: null argument in scan_next_with()\n");

  if (!expect_token(self, kind)) {
    return false;
  }
  scan_next(self);

  return true;
}

bool scan_token(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in scan_token()\n");

  char ch;

  while (1) {
    if (self->index >= self->source_length) {
      self->token = new_token(T_EOF);
      return true;
    }
    ch = get_char(self);
    if (ch == ' ' || ch == '\r' || ch == '\n') {
      self->index++;
      continue;
    }
    break;
  }

  switch (ch) {
    case '(': {
      self->token = new_token(T_OPEN_PAREN);
      self->index++;
      return true;
    }
    case ')': {
      self->token = new_token(T_CLOSE_PAREN);
      self->index++;
      return true;
    }
    case '{': {
      self->token = new_token(T_OPEN_BRACE);
      self->index++;
      return true;
    }
    case '}': {
      self->token = new_token(T_CLOSE_BRACE);
      self->index++;
      return true;
    }
    case '[': {
      self->token = new_token(T_OPEN_BRACKET);
      self->index++;
      return true;
    }
    case ']': {
      self->token = new_token(T_CLOSE_BRACKET);
      self->index++;
      return true;
    }
    case ';': {
      self->token = new_token(T_SEMI);
      self->index++;
      return true;
    }
    case '+': {
      self->token = new_token(T_PLUS);
      self->index++;
      return true;
    }
    case '-': {
      self->token = new_token(T_MINUS);
      self->index++;
      return true;
    }
    case '*': {
      self->token = new_token(T_ASTER);
      self->index++;
      return true;
    }
    case '/': {
      self->token = new_token(T_SLASH);
      self->index++;
      return true;
    }
    case '%': {
      self->token = new_token(T_PERCENT);
      self->index++;
      return true;
    }
  }

  if (scan_word(self)) {
    return true;
  }

  printf("SyntaxError: unexpected token\n");

  return false;
}

static bool scan_word(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in scan_word()\n");

  char ch;
  int length;
  uint8_t buf[32];
  bool is_number;

  length = 0;
  while (!is_eof(self) && length < 32) {
    ch = get_char(self);
    if (length == 0) {
      is_number = (ch >= '0' && ch <= '9');
    }
    if (is_number) {
      // TODO: invalid char error [A-Za-z_]
      if (!(ch >= '0' && ch <= '9')) {
        break;
      }
    } else {
      if (!(ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z' || ch == '_' || ch >= 'a' && ch <= 'z')) {
        break;
      }
    }
    buf[length] = ch;
    length++;
    self->index++;
  }
  if (length == 0) {
    return false;
  }
  if (is_number) {
    // create token
    self->token = new_token(T_NUMBER_LITERAL);
    self->token->value_length = length;
    // copy value
    self->token->value_ptr = malloc(length + 1);
    for (int i = 0; i < length; i++) {
      *(self->token->value_ptr + i) = buf[i];
    }
    *(self->token->value_ptr + length) = '\0';
    return true;
  }

  // keyword
  if (length == 2) {
    if (memcmp(buf, "if", 2) == 0) {
      self->token = new_token(T_IF);
      return true;
    }
  }
  else if (length == 4) {
    if (memcmp(buf, "else", 4) == 0) {
      self->token = new_token(T_ELSE);
      return true;
    }
  }

  // identifier token
  self->token = new_token(T_IDENTIFIER);
  self->token->value_length = length;
  self->token->value_ptr = malloc(length + 1);
  memcpy(self->token->value_ptr, buf, length);
  *(self->token->value_ptr + length) = '\0';

  return true;
}

// utility

static char get_char(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in get_char()\n");

  if (is_eof(self)) PANIC("FAIL: EOF in get_char()\n");

  return *(self->source + self->index);
}

static bool is_eof(scanner_t *self) {
  if (self == NULL) PANIC("FAIL: null argument in is_eof()\n");

  return (self->index >= self->source_length);
}

static token_t *new_token(token_kind_t kind) {
  token_t *ptr;

  ptr = malloc(sizeof(token_t));
  if (ptr == NULL) PANIC("FAIL: malloc\n");

  ptr->kind = kind;
  ptr->value_ptr = NULL;
  ptr->value_length = 0;

  return ptr;
}

char *get_token_name(token_kind_t kind) {
  switch (kind) {
    case T_EOF: return "EOF";
    case T_IDENTIFIER: return "Identifier";
    case T_NUMBER_LITERAL: return "NumberLiteral";
    case T_STRING_LITERAL: return "StringLiteral";
    case T_CHAR_LITERAL: return "CharLiteral";
    case T_OPEN_PAREN: return "\"(\"";
    case T_CLOSE_PAREN: return "\")\"";
    case T_OPEN_BRACKET: return "\"[\"";
    case T_CLOSE_BRACKET: return "\"]\"";
    case T_OPEN_BRACE: return "\"{\"";
    case T_CLOSE_BRACE: return "\"}\"";
    case T_SEMI: return "\";\"";
    case T_COMMA: return "\",\"";
    case T_PLUS: return "\"+\"";
    case T_MINUS: return "\"-\"";
    case T_ASTER: return "\"*\"";
    case T_SLASH: return "\"/\"";
    case T_PERCENT: return "\"\%\"";
    case T_EQ1: return "\"=\"";
    case T_EQ2: return "\"==\"";
    case T_LT: return "\"<\"";
    case T_LTE: return "\"<=\"";
    case T_GT: return "\">\"";
    case T_GTE: return "\">=\"";
    case T_AND1: return "\"&\"";
    case T_AND2: return "\"&&\"";
    case T_OR1: return "\"|\"";
    case T_OR2: return "\"||\"";
    case T_EXCL: return "\"!\"";
    case T_DOT: return "\".\"";
    case T_ARROW: return "\"->\"";
    case T_HAT: return "\"^\"";
    case T_TILDE: return "\"~\"";
    case T_QUEST: return "\"?\"";
    case T_COLON: return "\":\"";
    case T_IF: return "\"if\"";
    case T_ELSE: return "\"else\"";
  }
}
