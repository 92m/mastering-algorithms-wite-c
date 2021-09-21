/* chtbl.c */
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "chtbl.h"

/* chtbl_init */
int chtbl_init(
    CHTbl *htbl, 
    int buckets, 
    int (*h)(const void *key), 
    int (*match)(const void *key1, const void *key2), 
    void (*destroy)(void *data)
  ) 
{
  int i;

  /* Allocate space for the hash table */
  if((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL) {
    return -1;
  }

  /* Initalize the buckets. */
  htbl->buckets = buckets;
 
  for (i = 0; i < htbl->buckets; i++)
  {
    list_init(&htbl->table[i], destroy);
  }

  /* Encapsulate the functions */
  htbl->h = h;
  htbl->match = match;
  htbl->destroy = destroy;

  /* Initialize the number of elements in the table. */
  htbl->size = 0;

  return 0;
}

/* 销毁哈希表 */
int chtbl_destroy(CHTbl *htbl) {
  int i;

  /* Destroy each bucket.*/
  for (i = 0; i < htbl->buckets; i++)
  {
    list_destroy(htbl->table[i]); 
  }
  /* Free the storage allocated for now, but clear the structure as a precaution */
  memset(htbl, 0, sizeof(CHTbl));

  return 0;
}