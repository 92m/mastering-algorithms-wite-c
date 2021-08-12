#ifndef SINGLELIST_H__
#define SINGLELIST_H__

#include <stdlib.h>

/* 
* Define a structure for linked list elements. 
*/
typedef struct ListElmt_ {
 void *data;
 struct ListElmt_ *next;
} ListElmt;

/*
* Define a structure for linked lists.
*/
typedef struct List_ {
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  ListElmt *head;
  ListElmt *tail;
} List;

/*
* Public Interface
*/

/* 初始化链表 */
int list_init(List* list, void (*destroy)(void *data));

/* 销毁指定链表 */
int list_destroy(List *list);

/* 指定节点插入新数据 */
int list_ins_next(List *list, ListElmt *element, const void *data);

/* 移除指定节点的数据 */
int list_rem_next(List *list, ListElmt *element, void **data);

/* 返回链表长度 */
#define list_size(list) (list->size)

/* 返回链表头元素 */
#define list_head(list) (list->head)

/* 返回链表尾元素 */
#define list_tail(list) (list->tail)

/* 返回指定节点元素是否链表头元素 */
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

/* 返回指定节点元素是否链表尾元素 */
#define list_is_tail(element) ((element).next == NULL ? 1 : 0)

/* 返回指定节点元素数据 */
#define list_data(element) ((element)->data)

/* 返回指定节点元素下个元素指针 */
#define list_next(element) ((element)->next)

#endif /* SINGLELIST_H__ */
