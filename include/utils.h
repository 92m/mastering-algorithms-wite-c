#ifndef MALGORITHMS_H__
#define MALGORITHMS_H__

typedef struct ListElmt_ {
 void *data;
 struct ListElmt_ *next;
} ListElmt;


int g(int **iptr);

void swap(int *x, int *y);


#endif