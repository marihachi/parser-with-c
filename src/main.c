#include <stdio.h>
#include "parse.h"
#include "list.h"

#ifndef TEST_MODE

int main(void) {
  node_t *program;
  list_ptr_t decls;

  char *source = "foo";

  program = parse(source, 3);
  if (program == NULL) return 0;

  printf("program.kind %d\n", program->kind);
  decls = program->children;

  while (decls != NULL) {
    if (decls->item != NULL) {
      printf("decl.kind %d\n", ((node_t *)decls->item)->kind);
    }
    list_seek_next(&decls);
  }

  return 0;
}

#endif
