
#include <string.h>

#define TEST_CASE_REQUIRED 100
#define TEST_CASE_NOT_EXISTS 101
#define REGISTER_TEST(name) if (strcmp(argv[1], #name) == 0) return name()

// list of test case
int test_list(void);

int main(int argc, char* argv[]) {
  if (argc < 2) return TEST_CASE_REQUIRED;

  REGISTER_TEST(test_list);

  return TEST_CASE_NOT_EXISTS;
}
