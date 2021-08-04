#ifndef MALGORITHMS_H__
#define MALGORITHMS_H__

typedef struct ListElmt_ {
 void *data;
 struct ListElmt_ *next;
} ListElmt;

typedef ListElmt List[];

/* 全局状态变量 */  
enum {
  COMPUTE_OK = 0,
  COMPUTE_EXPECT_VALUE,
  COMPUTE_INVALID_VALUE
};

int g(int **iptr);

int fact(int n);

int facttail(int n, int a);

void swap(int *x, int *y);

void swap2(void *x, void *y, int size);

/* 移除 第五讲实现 */
int list_rm_next(List *list, ListElmt *element, void **data);

/*  */


#endif /* MALGORITHMS_H__ */