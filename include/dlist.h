#ifndef DOUBLELIST_H__
#define DOUBLELIST_H__

#include <stdlib.h>

/* Define a structure for doubly-linked list elements. */
typedef struct DlistElmt_ 
{
    void *data;
    struct DlistElmt_ *prev;
    struct DlistElmt_ *next;
} DlistElmt;

/* Define a structure for doubly-linked lists. */
typedef struct Dlist_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);   
    DlistElmt *head;
    DlistElmt *tail;
}Dlist;

/* Public Interface */

/* 初始化双向链表 */
int dlist_init(Dlist *list, void (*destroy)(void *data));

/* 销毁双向链表 */
int dlist_destroy(Dlist *list);

/* 向双向链表中的指定元素后插入新元素 */
int dlist_ins_next(Dlist *list, DlistElmt *element, const void *data);

/* 向双向链表中的指定元素前插入新元素 */
int dlist_ins_prev(Dlist *list, DlistElmt *element, const void *data);

/* 移除双向链表的指定元素 */
int dlist_remove(Dlist *list, DlistElmt *element, void **data);

/* 返回链表的长度个数 */
#define dlist_size(list) ((list)->size)

/* 返回链表的首元素 */
#define dlist_head(list) ((list)->head)

/* 返回链表的尾元素 */
#define dlist_tail(list) ((list)->tail)

/* 判断元素是否为链表的首元素 */
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)

/* 判断元素是否为链表的尾元素 */
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

/* 返回链表元素的数据 */
#define dlist_data(element) ((element)->data)

/* 返回链表元素前位元素 */
#define dlist_next(element) ((element)->next)

/* 返回链表元素前位元素 */
#define dlist_prev(element) ((element)->prev)

#endif /* DOUBLELIST_H__ */