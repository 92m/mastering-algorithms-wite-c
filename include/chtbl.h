#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

/* Define a structure for chained hash table */

typedef struct CHTbl_ 
{
  int  buckets;
  int  (*h)(const void *key);
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  int size;
  List *table;
} CHTbl;

/* Public Interface */

/* 初始化哈希表 */
int chtbl_init(
  CHTbl *htbl, 
  int buckets, 
  int (*h)(const void *key), 
  int (*match)(const void *key1, const void *key2),
  void (*destroy)(void *data)
  );

/* 销毁哈希表 */
int chtbl_destroy(CHTbl *htbl);

/* 向指定哈希表插入元素 */
int chtbl_insert(CHTbl *htbl, const void *data);

/* 在指定哈希表移除元素 */
int chtbl_remove(CHTbl *htbl, void **data);

/* 在指定哈希查找元素 */
int chtbl_lookup(CHTbl *htbl, void **data);

/* 获取链式哈希元素数量 */
#define chtbl_size(htbl) ((htbl)->size);

#endif /* CHTBL_H */