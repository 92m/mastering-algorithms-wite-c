#include <stdio.h>
#include "utils.h"

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


static void test_single_list_init() {
  #if 1
    List l;
    EXPECT_EQ_INT(list_init(&l, NULL), 0);
    EXPECT_EQ_INT(list_destroy(&l), 0);
  #endif
} 

static void test_single_list_ins_next() {
  #if 1
    List l2, *l2p;
    int CINT = 100;
    char *CSR = "dsadadasdada\0";
    l2p = &l2;
    EXPECT_EQ_INT(list_init(l2p, NULL), 0);
    EXPECT_EQ_INT(list_ins_next(l2p, NULL, &CINT), 0);
    EXPECT_EQ_INT(list_ins_next(l2p, NULL, &CSR), 0);
    EXPECT_EQ_INT((list_size(l2p)), 2);
    EXPECT_EQ_INT(list_destroy(l2p), 0);
  #endif
}

static void test_duble_list_ins_next() {
  Dlist dl;
  char *CSR = "dsadadasdada\0";
  EXPECT_EQ_INT(dlist_init(&dl, NULL), 0);
  EXPECT_EQ_INT(dlist_ins_next(&dl, NULL, &CSR), 1);
  EXPECT_EQ_INT(dlist_size(&dl), 1);
  EXPECT_EQ_INT(dlist_remove(&dl, NULL, NULL), 1);
  EXPECT_EQ_INT(dlist_destroy(&dl), 1);
}

static void test_parse() {
  test_fact();
  test_facttail();
  test_single_list_init();
  test_single_list_ins_next();
  test_duble_list_ins_next();
} 

int main(int argc, char** argv) {
  test_parse();
  printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
  return main_ret;
}
