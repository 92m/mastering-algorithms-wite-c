#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <stdio.h>
#include "utils.h"
#include <string.h>

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

  
#define EXPECT_EQ_STRING(expect, actual, alength) \
    EXPECT_EQ_BASE(sizeof(expect) - 1 == alength && memcmp(expect, actual, alength) == 0, expect, actual, "%s")
#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void test_fact() {
  EXPECT_EQ_INT(6, fact(3));
}

static void test_facttail() {
  EXPECT_EQ_INT(6, facttail(3, 1));
}


static void test_single_list() {
    List l2, *l2p;
    int CINT = 100;
    char *CSR = "dsadadasdada\0";
    l2p = &l2;
    EXPECT_EQ_INT(list_init(l2p, NULL), 0);
    EXPECT_EQ_INT(list_ins_next(l2p, NULL, &CINT), 0);
    EXPECT_EQ_INT(list_ins_next(l2p, NULL, &CSR), 0);
    EXPECT_EQ_INT((list_size(l2p)), 2);
    EXPECT_EQ_INT(list_destroy(l2p), 0);
}

static void test_duble_list() {

  Dlist dl;
  char *CSR = "dsad";
  int *inum = (int *)520, *inum2 = (int *)510;
  size_t len = 7;
  void *data;
  EXPECT_EQ_INT(dlist_init(&dl, NULL), 0);
  EXPECT_EQ_INT(dlist_ins_next(&dl, NULL, CSR), 0);
  EXPECT_EQ_INT(dlist_ins_next(&dl, (dlist_tail(&dl)), inum), 0);
  EXPECT_EQ_INT(dlist_ins_prev(&dl, (dlist_tail(&dl)), inum2), 0);
  EXPECT_EQ_INT(dlist_size(&dl), 3);
  EXPECT_EQ_STRING((char *)dlist_data(dl.head), "dsad", len);
  EXPECT_EQ_INT((int *)dlist_data(dl.tail), 520);
  EXPECT_EQ_INT(dlist_remove(&dl, dlist_tail(&dl), (void **)&data), 0);
  EXPECT_EQ_INT(dlist_remove(&dl, dlist_head(&dl), (void **)&data), 0);
  EXPECT_EQ_INT(dlist_size(&dl), 1);
  EXPECT_EQ_INT(dlist_destroy(&dl), 1);
  /* 
   * printf( "p dlist_head : %p\n", dlist_head(&dl)); 
   * printf( "CSR : %s\n", CSR);
   * printf( "p dlist_data : %s\n", (char *)dlist_data(dl.head)); 
   * printf( "p dlist_data : %d\n", (int *)dlist_data(dl.tail)); 
   */
}

static void test_clist_list() {
  Clist cl;
  char *CSR = "IIII";
  size_t len = 7;
  int *inum = (int *)520;
  EXPECT_EQ_INT(clist_init(&cl, NULL), 0);
  EXPECT_EQ_INT(clist_ins_next(&cl, NULL, inum), 0);
  EXPECT_EQ_INT(clist_data(clist_head(&cl)), 520);
  EXPECT_EQ_INT(clist_ins_next(&cl, clist_head(&cl), CSR), 0);
  EXPECT_EQ_STRING((char *)clist_data(cl.head->next), "IIII", len);
  EXPECT_EQ_INT(clist_size(&cl), 2);
  /*
  * printf("(char *)clist_data(clist_head(&cl)): %s\n",cl.head->next->data);
  */
}
static void test_page() {
  Clist cl;
  Page page1;
  page1.number = 1;
  page1.reference = 0;
  
  EXPECT_EQ_INT(page1.number, 1);
  EXPECT_EQ_INT(page1.reference, 0);

  clist_init(&cl, NULL);
  clist_ins_next(&cl, NULL, &page1);
  EXPECT_EQ_INT(clist_size(&cl), 1);

  replace_page(&clist_head(&cl));
}

static void test_stack() {
  Stack st1;
  int *inum = (int *)520;
  EXPECT_EQ_INT(stack_init(&st1, NULL), 0);
  EXPECT_EQ_INT(stack_push(&st1, inum), 0);
  EXPECT_EQ_INT(stack_size(&st1), 1);
}

static void test_queue() {
  Queue quq;
  int *inum = (int *)520;
  EXPECT_EQ_INT(queue_init(&quq, NULL), 0);
  EXPECT_EQ_INT(queue_enqueue(&quq, inum), 0);
  EXPECT_EQ_INT(queue_size(&quq), 1);
}

int set_match(const void *key1, const void *key2) {
  if(key1 == key2) 
    return 1;
  else 
    return 0;
}

static void test_set_list() {
  Set set;
  const int *inum = (int *)520;
  const int *inum2 = (int *)50;
  EXPECT_EQ_INT(set_init(&set, set_match, NULL), 0);
  EXPECT_EQ_INT(set_insert(&set, inum), 0);
  EXPECT_EQ_INT(set_remove(&set, &inum2), -1);
  EXPECT_EQ_INT(set_size(&set), 1);
}

static void test_parse() {
  #if 1
  test_fact();
  test_facttail();
  test_single_list();
  test_duble_list();
  test_clist_list();
  test_page();
  test_stack();
  test_queue();
  #endif
  test_set_list();
} 

int main(int argc, char** argv) {
  test_parse();
  printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
  return main_ret;
}
