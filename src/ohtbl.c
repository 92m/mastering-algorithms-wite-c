/* ohtbl.c */
#include <stdlib.h>
#include <string.h>

#include "ohtbl.h"

/* Reserve a sentinel memory address for vacated element. */
static char vacated;

/* 开地址哈希表初始化 */
int ohtbl_init(
  OHTbl *htbl,
  int positions, 
  int (*h1)(const void *key), 
  int (*h2)(const void *key),
  int  (*match)(const void *key1, const void *key2),
  void (*destroy)(void *data)
) {
  int i;

  /* Allcate space for the hash table. */
  if((htbl->table =(void **)malloc(positions * sizeof(void *))) == NULL) {
    return -1;
  }

  /* Intialize each position. */

  htbl->positions = positions;

  for (i = 0; i < htbl->positions; i++)
  {
    htbl->table[i] =  NULL;
  }

  /* Set the vacated member to the sentinel memory address reserved for this. */
  htbl->vacated = &vacated;

  /* Initialize the number of elements in the table. */
  htbl->size = 0;

  return 0;
}

/* 开地址哈希表销毁 */
void ohtbl_destroy(OHTbl *htbl) {
  int i;

  if(htbl->destroy != NULL) {
    /* Call a user-defined function to free dynmically allocated data. */
    for(i=0; i < htbl->positions; i++) {
      if(htbl->table[i] != NULL && htbl->table[i] != htbl->vacated) {
        htbl->destroy(htbl->table[i]);
      }
    }
  }

  /* Free the storage allocated for the hash table. */
  free(htbl->table);

  /* No operations are allowed now,  but clear the structure as a precaution. */
  memset(htbl, 0, sizeof(OHTbl));

  return;
}

/* 在指定开地址哈希表插入元素 */
int ohtbl_insert(OHTbl *htbl, const void *data) {
  void *temp;
  int postion, i;

  /* Dn not exceed the number of positons in the table. */
  if(htbl->size == htbl->positions) {
    return -1;
  }

  /* Do nothing if the data is already in the table. */

  temp = (void *)data;
  if(ohtbl_lookup(htbl, &temp) == 0) {
    return 1;
  }

  /* Use double hashing to hash the key. */
  for(i = 0; i < htbl->positions; i++) {
    postion = (htbl->h1(data) + (i * htbl->h2(data))) % htbl->positions;

    if(htbl->table[postion] == NULL || htbl->table[postion] == htbl->vacated) 
    {
      /* Insert the data into the table. */
      htbl->table[postion] = (void *)data;
      htbl->size++;
      return 0;
    }
  }
  /* Return that the hash funtions were selected incorrectly. */
  return -1;
}