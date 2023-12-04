#include <string.h>
#include <stdio.h>
#include "parse.h"
#include "list.h"

#ifndef TEST_MODE

int main(void) {
  list_ptr_t iter;
  node_t *program;
  node_t *node;

  char *source = "int abc; int main(); int main() { }";

  program = parse(source, strlen(source));
  if (program == NULL) return 1;

  printf("program.kind %d\n", program->kind);

  iter = program->children;
  while (iter != NULL) {
    node = list_get_current(iter);
    if (node != NULL) {
      printf("node.kind %d\n", node->kind);
      if (node->name_ptr != NULL) {
        printf("node.name %s\n", node->name_ptr);
      }
    }
    list_seek_next(&iter);
  }

  return 0;
}

#endif
