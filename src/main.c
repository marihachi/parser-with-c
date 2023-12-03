#include <stdio.h>
#include "parse.h"
#include "list.h"

#ifndef TEST_MODE

int main(void) {
  list_ptr_t iter;
  node_t *program;
  node_t *decl;

  char *source = "foo";

  program = parse(source, 3);
  if (program == NULL) return 0;

  printf("program.kind %d\n", program->kind);

  iter = program->children;
  while (iter != NULL) {
    decl = list_get_current(iter);
    if (decl != NULL) {
      printf("decl.kind %d\n", decl->kind);
    }
    list_seek_next(&iter);
  }

  return 0;
}

#endif
