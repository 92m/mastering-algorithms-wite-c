#include <stdio.h>
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
   
  while (dlist_size(list) > 0)
  {
    if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL) {
      list->destroy(data);
    } 
  }
  memset(list, 0, sizeof(Dlist));
  return 1;
}

/* 移除双向链表的指定元素 */
int dlist_remove(Dlist *list, DlistElmt *element, void **data) {

  /* DO not allow a NULL element or removal from an empty list */
  if(element == NULL && dlist_size(list) == 0) {
    return -1;
  }
  /* Remove the element from the list. */
  *data = element->data;

  if (element == list->head) {

     /* Handle removal from the head of the list. */
    list->head = element->next;

    if(list->head == NULL)
      list->tail = NULL;
    else
      element->next->prev = NULL;
    
  } else {
    /* Handle removal from other than the head of the list */
    element->prev->next = element->next;
    if(element->next == NULL) {
      list->tail = element->prev;
    } else {
      element->next->prev = element->prev;
    }
  }

  /* Free the storage allocated by the abstract datatype */
  free(element);

  /* Adjust the size of the list of account for the removal element. */
  list->size--;
  return 0;
}

/* 向双向链表中的指定元素后插入新元素 */
int dlist_ins_next(Dlist *list, DlistElmt *element, const void *data) {
  DlistElmt *new_element;

  /* 
   * 除非列表为空，否则不允许使用 NULL 元素
   */
  if(element == NULL && dlist_size(list) !=0) 
    return -1; 

  /* 为该元素分配存储空间 */
  if((new_element = (DlistElmt *)malloc(sizeof(DlistElmt))) == NULL) 
    return -1;

  /* 将新元素插入列表. */
  new_element->data = (void *)data;
  /*
  *  如插入空链表，元素可能指向任何位置为了避免混淆此时element设置为NULL 
  */
  if (dlist_size(list) == 0)
  {
    /* 列表为空时，把元素插入列表插入. */
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }
  else 
  {  
    /* 列表不为空时，把元素插入列表插入. */
    new_element->next = element->next;
    new_element->prev = element;

    if(element->next == NULL) {
      list->tail = new_element;
    }
    else {
      element->next->prev = new_element;
    }
    element->next = new_element;
  }
  list->size++; 
  return 0;
}

/* 向双向链表中的指定元素前插入新元素 */
int dlist_ins_prev(Dlist *list, DlistElmt *element, const void *data) {
  DlistElmt *new_element;

  /* 
   * 除非列表为空，否则不允许使用 NULL 元素
   */
  if(element == NULL && dlist_size(list) !=0) 
    return -1; 

  /* 为该元素分配存储空间 */
  if((new_element = (DlistElmt *)malloc(sizeof(DlistElmt))) == NULL) 
    return -1;

  /* 将新元素插入列表. */
  new_element->data = (void *)data;
  
  /*
  *  如插入空链表，元素可能指向任何位置为了避免混淆此时element设置为NULL 
  */
  if(dlist_size(list) == 0) 
  {
    /* 列表为空时，把元素插入列表插入. */
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } 
  else 
  {
    /* 列表不为空时，把元素插入列表插入. */
    new_element->prev = element->prev;
    new_element->next = element;
    element->prev = new_element;
    
    if(new_element->prev == dlist_tail(list)) {
      list->head = new_element;
    }
  }
  list->size++;
  return 0;
}