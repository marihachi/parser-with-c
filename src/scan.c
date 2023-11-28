#include "scan.h"

static bool scan_token(scanner_t *self);
static bool scan_word(scanner_t *self);
static char get_char(scanner_t *self);
static bool is_eof(scanner_t *self);
static token_t *new_token(token_kind_t kind);

scanner_t *new_scanner(char *source, int source_length) {
  scanner_t *ptr;
  ptr = malloc(sizeof(scanner_t));

  if (ptr == NULL) {
    printf("FAIL: malloc in new_scanner()\n");
    while (1) {}
  }

  ptr->source = source;
  ptr->source_length = source_length;
  ptr->index = 0;
  ptr->line = 0;
  ptr->column = 0;
  ptr->token = NULL;
  scan_token(ptr);

  return ptr;
}

token_t *get_token(scanner_t *self) {
  return self->token;
}

token_kind_t get_kind(scanner_t *self) {
  token_t * token = get_token(self);
  if (token == NULL) {
    printf("FAIL: get token in get_kind()\n");
    while (1) {}
  }
  return token->kind;
}

bool scan_next(scanner_t *self) {
  if (get_kind(self) == T_EOF) {
    return true;
  }
  return scan_token(self);
}

bool expect_token(scanner_t *self, token_kind_t kind) {
  if (get_kind(self) != kind) {
    printf("SyntaxError: unexpected token\n");
    return false;
  }
  return true;
}

bool scan_next_with(scanner_t *self, token_kind_t kind) {
  if (!expect_token(self, kind)) {
    return false;
  }
  scan_next(self);
  return true;
}

static bool scan_token(scanner_t *self) {
  char ch;

  if (self->index >= self->source_length) {
    self->token = new_token(T_EOF);
    return true;
  }

  ch = get_char(self);

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
  }

  if (scan_word(self)) {
    return true;
  }

  printf("SyntaxError: unexpected token\n");
  return false;
}

static bool scan_word(scanner_t *self) {
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
    self->token->value_ptr = malloc(length);
    for (int i = 0; i < length; i++) {
      *(self->token->value_ptr + i) = buf[i];
    }
    return true;
  }

  // keyword
  // if (length == 2 && memcmp(buf, "if", 2) == 0) {
  //   self->token = new_token(T_IF);
  //   return true;
  // }
  // if (length == 3 && memcmp(buf, "var", 3) == 0) {
  //   self->token = new_token(T_VAR);
  //   return true;
  // }
  // if (length == 4 && memcmp(buf, "else", 4) == 0) {
  //   self->token = new_token(T_ELSE);
  //   return true;
  // }

  // identifier token
  self->token = new_token(T_IDENTIFIER);
  self->token->value_length = length;
  self->token->value_ptr = malloc(length);
  memcpy(self->token->value_ptr, buf, length);

  return true;
}

// utility

static char get_char(scanner_t *self) {
  if (is_eof(self)) {
    printf("FAIL: EOF in get_char()\n");
    while (1) {}
  }
  return *(self->source + self->index);
}

static bool is_eof(scanner_t *self) {
  return (self->index >= self->source_length);
}

static token_t *new_token(token_kind_t kind) {
  token_t *ptr;

  ptr = malloc(sizeof(token_t));
  if (ptr == NULL) {
    printf("FAIL: malloc\n");
    while (1) {}
  }

  ptr->kind = kind;
  ptr->value_ptr = NULL;
  ptr->value_length = 0;

  return ptr;
}
