/* ottbl.h */

#ifndef OHTBL_H
#define OHTBL_H

#include <stdlib.h>

/* Denfine a structure for open-address hash tables. */
typedef struct OHTbl_ { 
  int  positions;
  void *vacated;

  int  (*h1)(const void *key);
  int  (*h2)(const void *key);
  int  (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  int size;
  void **table;

} OHTbl;

/* Publice Interface */

/* 开地址哈希表初始化 */
int ohtbl_init(
  OHTbl *htab, 
  int positions, 
  int (*h1)(const void *key), 
  int (*h2)(const void *key),
  int  (*match)(const void *key1, const void *key2),
  void (*destroy)(void *data)
);

/* 开地址哈希表销毁 */
void ohtbl_destroy(OHTbl *htbl);

/* 在指定开地址哈希表插入元素 */
int ohtbl_insert(OHTbl *htbl, const void *data);

/* 移除指定开地址哈希表元素 */
int ohtbl_remove(OHTbl *htbl, const void *data);

/* 在指定开地址哈希表查找元素 */
int ohtbl_lookup(const OHTbl *htbl, void **data);

#define ohtbl_size(htbl) ((htbl)->size)
#endif