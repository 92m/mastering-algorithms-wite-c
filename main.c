#include "utils.h"
#include <stdio.h>

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
  do {\
    test_count++;\
    if (equality)\
      test_pass++;\
    else {\
      fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
      main_ret = 1;\
    }\
  } while(0)

  

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void test_fact() {
  EXPECT_EQ_INT(6, fact(3));
}

static void test_facttail() {
  EXPECT_EQ_INT(6, facttail(3, 1));
}

static void test_parse() {
  test_fact();
  test_facttail();
} 

int main(int argc, char** argv) {
  test_parse();
  printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
  return main_ret;
}
