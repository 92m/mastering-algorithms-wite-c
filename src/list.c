#include <stdlib.h>
#include <string.h>

#include "list.h"

/* 
* 函数定义：初始化链表 
* 复杂度： O(1)
*/
int list_init(List *list, void (*destroy) (void *data)) {
  /* Initialize the list. */

  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return 0;
}

/* 
* 函数定义：销毁指定链表 
* 复杂度： O(n)
*/
int list_destroy(List *list) {
  void *data;

  /* Remove each element. */
  while(list_size(list) > 0) {
    if(list_rem_next(list, NULL,(void **)&data) == 0 && list->destroy != NULL) {
      /*  */
      list->destroy(data);
    }
  }
  /* No opertions are allowed now, but not clear the strcture  as a precaution. */
  memset(list, 0, sizeof(List));
  return 0;
}

/*  
* 函数定义：指定节点插入新数据 
* 复杂度：O(1)
*/
int list_ins_next(List *list, ListElmt *element, const void *data) {
  ListElmt *new_element;

  /* Allocate stotage for this element. */
  if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL ) {
    return -1;
  }

  /* Insert the element into the list. */
  new_element->data = (void *)data;
  if(element == NULL) {
    
    /* Handle insertion at the head of the list */
    if (list_size(list) == 0) 
    list->tail = new_element;

    new_element->next = list->head;
    list->head = new_element;

  } else {
    /* Handle insertion somewhere other than at the head  */
    if (element->next==NULL) 
    list->tail = new_element;

    new_element->next = element->next;
    element->next = new_element;
  }
  /* Ajust the size of the list to accout for insertion element. */
  list->size++;
  return 0;
}

/* 
* 函数定义：移除指定节点的数据
* 复杂度：复杂度：O(1)
 */
int list_rem_next(List *list, ListElmt *element, void **data) {
  ListElmt *old_element;
  /* Do not allow removal from an empty list. */
  if(list_size(list) == 0) {
    return -1;
  }
  /* Removal the element from the list */ 
  if(element == NULL) {
    /* Handle the element from the list */ 
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;
    if (list_size(list) == 1) {
      list->tail = NULL;
    }
  } else {
    *data = element->next->data;
    old_element = element->next;
    element->next = element->next->next;

    if(element->next == NULL)
      list->tail = element;
  }
  /* Free the strorage allowated by the abstract datatype */
  free(old_element);

  /* Ajust the size of the list to accout for insertion element. */
  list->size--;
  return 0;
}

