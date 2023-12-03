#include <string.h>

#define TEST_CASE_REQUIRED 100
#define TEST_CASE_NOT_EXISTS 101

#define REGISTER_TEST(name) if (strcmp(argv[1], #name) == 0) return name()

// declare test cases
int test_list_add(void);
int test_list_insert(void);
int test_list_seek_next(void);

int main(int argc, char* argv[]) {
  if (argc < 2) return TEST_CASE_REQUIRED;

  // register test cases
  REGISTER_TEST(test_list_add);
  REGISTER_TEST(test_list_insert);
  REGISTER_TEST(test_list_seek_next);

  return TEST_CASE_NOT_EXISTS;
}
