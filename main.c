#include <stdio.h>
#include <stdlib.h>

typedef struct ListElmt_ {
 void *data;
 struct ListElmt_ *next;
} ListElmt;


int f(int **iptr) {
  int a = 10;
  *iptr = &a;
  return 0;
}

int g(int **iptr) {
  if((*iptr = (int *)malloc(sizeof(int))) == NULL) {
    return -1;
  }
  return 0;
}

int main(int argc, char** argv) {
  int N = 100;
  int sum = 0;
  int i = 1;

  // calculate sum from 1 to 100
  while (i <= N)
  {
    sum = sum + i;
    i = i + 1;
  }

  printf("sum = %d;\n", sum); 
  printf("The program is over. \n"); 
  return 0;
};