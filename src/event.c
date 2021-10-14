#ifndef BITREE_C
#define BITREE_C
#include <stdlib.h>

/* Define a structure for binary tree nodes. */
typedef struct  BiTreeNode_
{
  void *data;
  struct  BiTreeNode_ *left;
  struct  BiTreeNode_ *right;  
} BiTreeNode;

/* Define a struture for binary trees. */
typedef struct BiTree_
{
  int   size;
  int   (*compare)(const void *key, const void *key2);
  void  (*destroy)(void *data);
  BiTreeNode *root;
} BiTree;

/* Public Interface */
void bitree_init(BiTree *tree, void (*destroy)(void *data));