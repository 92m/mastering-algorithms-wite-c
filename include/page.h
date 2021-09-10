
#ifndef PAGE_H
#define PAGE_H
#include "clist.h"

typedef struct Page_
{
  int number;
  int reference;
}Page;

/* Publice Interface */

int replace_page(ClistElmt **current);

#endif 