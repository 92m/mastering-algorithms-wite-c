#ifndef MALGORITHMS_H__
#define MALGORITHMS_H__

typedef struct ListElmt_ {
 void *data;
 struct ListElmt_ *next;
} ListElmt;


int g(int **iptr);

int fact(int n); 

void swap(int *x, int *y);


void swap2(void *x, void *y, int size);


#endif