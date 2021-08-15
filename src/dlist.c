#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/* 
* 作用：初始化双向链表
* 复杂度： O(1)
*/
int dlist_init(Dlist *list, void (*destroy)(void *data)) {
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
  return 0;
}

/*
* 作用：销毁双向链表 
* 复杂度：O(1)
*/
int dlist_destroy(Dlist *list) {
  void *data;
  /*  */
  while (dlist_sise(list) > 0)
  {
    if(dlist_remove(list, dlist_tail(list), )) 
  }
  
  return 1;
}
