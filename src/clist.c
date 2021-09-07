
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clist.h"

int clist_init(Clist *list, void (*destroy)(void *data)) {
  list->size = 0;
  list->head = NULL;
  list->match = NULL;
  list->destroy = destroy;
  return 0;
}

int clist_destroy(Clist *list) {
  void *data;
  /* Remove each element */
  while (clist_size(list) > 0)
  {
    if(clist_rem_next(list, clist_head(list), (void **)&data) == 0&& list->destroy != NULL ) {
      list->destroy(data);
    } 
  }
  
  memset(list, 0, sizeof(Clist));
  return 0;
}

int clist_ins_next(Clist *list, ClistElmt *element, void *data) {
  ClistElmt *new_element;

  if((new_element = (ClistElmt *)malloc(sizeof(ClistElmt))) == NULL) {
    return -1;
  }

  new_element->data = (void *)data;

  if(clist_size(list) == 0) {
    new_element->next = new_element;
    list->head = new_element;
  } else {
    new_element->next = element->next;
    element->next = new_element;
  }
  list->size++;
  return 0;
}
int clist_rem_next(Clist *list, ClistElmt *element, void **data) {
  ClistElmt *old_element;
  
  if(clist_size(list) == 0) {
    return -1;
  }

  *data = element->next->data;

  if(element->next == element) {
    /* Handle removing  the last element. */
    old_element = element->next;
    list->head = NULL;
  }
  else 
  {
    /* Handle removing other than the last element. */
    old_element = element->next;
    element->next = element->next->next;
    if(old_element == clist_head(list)) {
      list->head = old_element->next;
    }

    free(old_element);
    list->size--;
    return 0;
  }


  return 0;
}