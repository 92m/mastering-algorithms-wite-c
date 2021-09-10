#include "clist.h"
#include "page.h"

int replace_page(ClistElmt **current) {
  /* Circle through the list of pages until one is founf to replace. */
  while (((Page *)(*current)->data)->reference != 0)
  {
    ((Page *)(*current)->data)->reference = 0;
    *current = clist_next(*current);
  }
  return ((Page *)(*current)->data)->number;
}