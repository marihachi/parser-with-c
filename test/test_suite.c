#include <stdio.h>

#define TEST_CASE_REQUIRED 100
#define INVALID_FORMAT 101
#define INVALID_TEST_CASE 102

int test_list() {
  return 0;
}

int main(int argc, char* argv[]) {
  int test_case, count;

  if (argc < 2) return TEST_CASE_REQUIRED;
  count = sscanf(argv[1], "%d", &test_case);
  if (count != 1) return INVALID_FORMAT;

  switch (test_case) {
    case 1: {
      return test_list();
    }
  }

  return INVALID_TEST_CASE;
}
