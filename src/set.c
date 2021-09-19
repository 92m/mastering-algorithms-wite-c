/* set.c */
#include "stdlib.h"
#include "string.h"
#include "list.h"
#include "set.h"

int set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
  list_init(set, destroy);
  set->match = match;
  return 0;
}

/* 往集合插入成员 */
int set_insert (Set *set, const void *data) {
  /* Do not allow the insertion of duplicates */
  if(set_is_member(set, data)) {
    return 1;
  }
  return list_ins_next(set, list_tail(set), data);
}

/* 在集合移除成员 */
int set_remove(Set *set, void **data) {
  ListElmt *member, *prev;

  /* Find the member to remove. */
  prev = NULL;

  for(member = list_head(set); member != NULL; member = list_next(member)) {
    if (set->match(*data, list_data(member)))
    break;
    prev = member;
  }

  /* Reture if the member was not fount */
  if (member==NULL) {
    return -1;
  }

  return list_rem_next(set, prev, data);
}

/* 计算并集 */
int set_union(Set *setu, const Set *set1, const Set *set2) {
  ListElmt *member;
  void *data;

  /* Initalize the set for the union. */
  set_init(setu, set1->match, NULL);

  /* Inser the members of the first set. */
  for (member = list_head(set1); member != NULL; member = list_next(member))
  {
    data = list_data(member);
    if(list_ins_next(setu, list_tail(setu), data) != 0) {
      set_destroy(setu);
      return -1;
    }
  }
  
  /* Inser the member of the second set */
  for (member = list_head(set2); member != NULL; member = list_next(member))
  {
    if(set_is_member(set1, list_data(member))) {
      /* Do not allow the insertion of duplicates */
      continue;
    }
    else
    {
      data = list_data(member);
      if(list_ins_next(setu, list_tail(setu), data) != 0) {
        set_destroy(setu);
        return -1;
      }
    }
  }
  return 0;
}
/* 计算交集 */
int set_intersection(Set *seti, const Set *set1, const Set *set2) {
  ListElmt *member;
  void *data;

  /* Initalize the sert for the intersection. */
  set_init(seti, set1->match, NULL);

  for (member=list_head(set1); member != NULL; member=list_next(member)) {
    if(set_is_member(set2, list_data(member))) {
      data = list_data(member);
      if(list_ins_next(seti, list_tail(seti), data) != 0) {
        set_destroy(seti);
        return -1;
      }
    }
  }
  return 0;
}
/* 计算差集 */
int set_difference(Set *setd, const Set *set1, const Set *set2) {
  ListElmt *member;
  void *data;
  /* Initialize the set for the difference. */
  set_init(setd, set1->match, NULL);

  for(member=list_head(set1); member!=NULL;member=list_next(member)) {
    if(!set_is_member(set2, list_data(member)))
    {
      data = list_data(member);

      if(list_ins_next(setd, list_tail(setd), data) != 0) {
        set_destroy(setd);
        return -1;
      }
    }
  }
  return 0;
}

/* 查找成员 */
int set_is_member(const Set *set, const void *data) {
  ListElmt *member;

  /* Determine if the data is a member of the set. */
  for (member = list_head(set); member != NULL; member = list_next(member))
  {
    /*
     * 原文调用set->match 函数在外部判断成员是否在集合里
     * if (set->match(data, list_data(member))) {
     *  return 1;    
     * }
     */
    if(data == list_data(member))
      return 1;
  }
  return 0;
}

/* 判断是否为指定集合的子集 */
int set_is_subset(const Set *set1, const Set *set2) {
  ListElmt *member;

  if(list_size(set1) > list_size(set2)) {
    return 0;
  }
  /* Deftermine if set1 is a subset of set2 */
  for (member=list_head(set1); member != NULL; member=list_next(member)) {
    if(!set_is_member(set2, list_data(member)))
    return 0; 
  }
  return 1; 
}

/* 判断指定集两个集合是否相等 */
int set_is_equal(const Set *set1, const Set *set2) {
  /* Do a quick test to rule out some cases.*/
  if(list_size(set1) != list_size(set2)) {
    return 0;
  }
  /* set of the same size are equal if they are subsets. */
  return set_is_member(set1, set2);
}