#include <string.h>
#include <stdio.h>
#include "parse.h"
#include "list.h"

#ifndef TEST_MODE

#define PAGE_SIZE 1024
char buf[PAGE_SIZE];

bool read_file(char *filepath, char *buf_ptr, int buf_size) {
  int i, c;
  int status;
  FILE *file;

  file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Error: open file failed\n");
    return false;
  }

  i = 0;
  while (1) {
    c = fgetc(file);
    if (ferror(file)) {
      printf("Error: read file failed\n");
      if (fclose(file) != 0) {
        printf("Error: close file failed\n");
      }
      return false;
    }
    if (c == EOF) {
      break;
    }
    if (i > buf_size-2) {
      printf("Error: too long file\n");
      if (fclose(file) != 0) {
        printf("Error: close file failed\n");
      }
      return false;
    }
    buf[i] = (char)c;
    i++;
  }
  buf[i] = '\0';

  if (fclose(file) != 0) {
    printf("Error: close file failed\n");
    return false;
  }

  return true;
}

int main(int argc, char* argv[]) {
  char *filepath;

  list_ptr_t iter;
  node_t *program;
  node_t *node;

  if (argc < 2) {
    printf("Error: Specify source file\n");
    return -1;
  }
  filepath = argv[1];

  // load source file

  if (!read_file(filepath, buf, sizeof(buf))) return 1;

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
