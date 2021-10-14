/* traverse.c */
#ifndef TRAVERSE_H
#define  TRAVERSE_H
#include <stdlib.h>
#include "list.h"
#include "bitree.h"

/* preorder */
int preorder(const BiTreeNode *node, List *list);

/* inorder */
int inorder(const BiTreeNode *node, List *list);

#endif