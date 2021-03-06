#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int swap2(void *x, void *y, int size) {
  void *tmp;
  if((tmp = malloc(size)) == NULL) 
    return -1;
    
  memcpy(tmp, x, size); memcpy(x, y, size); memcpy(y, tmp, size);

  free(tmp);

  return 0;
}

int fact(int n) {
  if (n < 0)
    return 0;
  else if ( n == 0)
    return 0;
  else if ( n == 1)
    return 1;
  else 
    return n * fact(n - 1);
}

int facttail(int n, int a) {
  /* Compute a facttail in a tail-recursive manner */
  if(n < 0)
    return 0;
  else if(n == 0) 
    return 1;
  else if(n == 1) 
    return a;
  else if (n > 1) 
    return facttail(n-1, n*a);
}

/* hashpjw.h */

unsigned int hashpjw(const void *key) {
  const char *ptr;
  unsigned int val;

  /* Hash the key by performiing a number of bit opration on it */
  val = 0;
  ptr = key;

  while (*ptr != '\0')
  {
    unsigned int tmp;
    val = (val << 4) + (*ptr);

    if ((tmp = (val & 0xf0000000))) 
    {
      val = val ^ (tmp >> 24);
      val = val ^ tmp;
    }
    ptr++;
  }

  /* In practice , replace PRIME_TBLSIZ with the actual table size */
  
  return val % 100;
}