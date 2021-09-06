/* clist.c */
#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

/* Defind a structure for curcular list elements. */

typedef struct ClistElmt_
{
  void *data;
  struct ClistElmt_ *next;
}ClistElmt;


/* Defind a struture for circular lsits. */
typedef struct Clist_
{
  int size;
  int (*match)(const void *key1, const  void *key2);
  void (*destroy)(void *data);
  ClistElmt *head;
}Clist;

/* Public Interface */
int clist_init(Clist *list, void (*destroy)(void *data));

#endif