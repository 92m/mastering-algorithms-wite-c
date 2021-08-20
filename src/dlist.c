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
  /* void *data;
   
  while (dlist_sise(list) > 0)
  {
    if(dlist_remove(list, dlist_tail(list), )) 
  }
  */
  return 1;
}

/* 移除双向链表的指定元素 */
int dlist_remove(Dlist *list, DlistElmt *element, const void **data) {
  DlistElmt *old_element;
  if(dlist_size(list) == 0) {
    return -1;
  }

  return 1;
}

/* 向双向链表中的指定元素后插入新元素 */
int dlist_ins_next(Dlist *list, DlistElmt *element, const void *data) {
  DlistElmt *new_element;
  /* 为该元素分配存储空间 */
  if((new_element = (DlistElmt *)malloc(sizeof(DlistElmt))) == NULL) {
    return -1;
  }

  new_element->data = (void *)&data;

  if(element == NULL) {
    if(dlist_size(list) == 0) 
      list->head = new_element;
    list->tail = new_element;
  } else {
    if (element->next == NULL)
      element->next = new_element;
    new_element->next = element->next;

  }

  list->size++;
  return 1;
}