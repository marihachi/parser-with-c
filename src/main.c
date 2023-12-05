#include <string.h>
#include <stdio.h>
#include "parse.h"
#include "list.h"

#ifndef TEST_MODE

#define PAGE_SIZE 1024
char buf[PAGE_SIZE];

int main(int argc, char* argv[]) {
  char *filepath;
  int i, c;
  int status;
  FILE *file;

  list_ptr_t iter;
  node_t *program;
  node_t *node;

  // arguments

  if (argc < 2) {
    printf("Error: Specify source file\n");
    return -1;
  }
  filepath = argv[1];

  // source file

  file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Error: open file failed\n");
    return 1;
  }

  i = 0;
  while (1) {
    c = fgetc(file);
    if (ferror(file)) {
      printf("Error: read file failed\n");
      if (fclose(file) != 0) {
        printf("Error: close file failed\n");
      }
      return 1;
    }
    if (c == EOF) {
      break;
    }
    if (i > PAGE_SIZE-2) {
      printf("Error: too long file\n");
      if (fclose(file) != 0) {
        printf("Error: close file failed\n");
      }
      return 1;
    }
    buf[i] = (char)c;
    i++;
  }
  buf[i] = '\0';

  if (fclose(file) != 0) {
    printf("Error: close file failed\n");
    return 1;
  }

  // parse

  program = parse(buf, strlen(buf));
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
