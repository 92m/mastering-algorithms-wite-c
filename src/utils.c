#include <stdlib.h>
#include "utils.h"

int g(int **iptr) {
  if((*iptr = (int *)malloc(sizeof(int))) == NULL) {
    return -1;
  }
  return 0;
}

void swap(int *x, int *y) {
  int tmp;
  tmp = *x; *x = *y; *y = tmp;
  return;
}