#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

/* Define a structure for chained hash table */

typedef struct CHTbl_ 
{
  int  buckets;
  int  (*h)(const void *key);
  void (*match)(const void *key1, const void *key2);

  int size;
  List *table;
} CHTbl;

/* Public Interface */
int chtbl_int(CHTbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2) );

#endif /* CHTBL_H */