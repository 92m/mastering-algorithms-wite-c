#ifndef MALGORITHMS_H__
#define MALGORITHMS_H__

/*
* 引入单链表头部文件
*/
#include "singleList.h"

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

int swap2(void *x, void *y, int size);


#endif /* MALGORITHMS_H__ */
