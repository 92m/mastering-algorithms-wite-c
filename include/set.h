/* set.h */
#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "list.h"

/* Ipmlement sets as linked */
typedef List Set;

/* Publib Interface */
int set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

#define set_destroy list_destroy

/* 往集合插入成员 */
int set_insert (Set *set, const void *data) ;

/* 在集合移除成员 */
int set_remove(Set *set, void **data);

/* 计算并集 */
int set_union(Set *setu, const Set *set1, const Set *set2);

/* 计算交集 */
int set_intersection(Set *seti, const Set *set1, const Set *set2);

/* 计算差集 */
int set_difference(Set *serd, const Set *set1, const Set *set2);

/* 查找成员 */
int set_is_member(const Set *set, const void *data);

/* 判断指定集合子集 */
int set_is_subset(const Set *set1, const Set *set2);

/* 判断指定集两个集合是否相等 */
int set_is_equal(const Set *set1, const Set *set2);

#define set_size list_size


#endif /* SET_H */