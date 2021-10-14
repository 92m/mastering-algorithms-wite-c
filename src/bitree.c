/* bitree.c */
#include <stdlib.h>
#include <string.h>
#include "bitree.h"

/* 初始化二叉树 */
void bitree_init(BiTree *tree, void (*destroy)(void *data)) 
{
  /* Initalize the binary tree */
  tree->size = 0;
  tree->root = NULL;
  tree->destroy = destroy;
  return;
}

/* 销毁二叉树 */  
void bitree_destroy(BiTree *tree) {
  /* Remove all the node from the tree. */
  bitree_rem_left(tree, NULL);

  /* No oprations are allowed now, but clear the structure as a precaution */
  memset(tree, 0, sizeof(BiTree));

  return;
}


/* 在指定树左结点插入元素结点 */
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data) {
  BiTreeNode *new_node, **position;

  /* Determine where to insert the node. */
  if(node == NULL) {
    /* Allow insertion at the root only in an empty tree. */
    /* 只允许在树的根部插入空结点 */
    if(bitree_size(tree) > 0) 
      return -1;
    
    position = &tree->root;
  }
  else
  {
    /* Normally allow insertion only at the end of a branch. */
    if(bitree_left(node) != NULL) 
      return -1;
    
    position = &node->left;
  }

  /* Allocate storage for the node. */
  if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
    return -1;
  
  /* Insert the node into tree. */
  new_node->data  =  (void *)data;
  new_node->left  =  NULL;
  new_node->right =  NULL;

  *position = new_node;

  /* Adjust the size of the tree to acount for the inserted node. */
  tree->size++; 

  return 0;
}

/* 在指定树右结点插入元素结点 */
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data) {
  BiTreeNode *new_node, **position;
  
  /* Determine where to insert the node */
  if(node == NULL) 
  {
    /* Allow insertion at the root only in an  empty  tree. */
    if (bitree_size(tree) > 0)
      return -1;

    position = &tree->root;
  }
  else 
  {
    /* Normally allow insertion only at the end of a branch. */
    if (bitree_right(node) != NULL)
      return -1;
    
    position = node->right;
  }

  /* Allocate storage for the tree. */
  if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL ) 
    return -1;

  /* Insert the node into tree. */
  new_node->data  =  (void *)data;
  new_node->left  =  NULL;
  new_node->right =  NULL;

  *position = new_node;

  /* Adjust the size of the tree to acount for the inserted node. */
  tree->size++; 

  return 0;
}


/* 移除树的左结点 */
void bitree_rem_left(BiTree *tree, BiTreeNode *node) {
  BiTreeNode **position;

  /* Do not allow removal from an empty tree. */
  if(bitree_size(tree) == 0) {
    return;
  }

  /* Determine where to remove nodes. */
  if (node == NULL)
    position = &tree->root;
  else 
    position = &node->left;

  /* Remove the nodes. */
  if(*position == NULL) 
  {
    bitree_rem_left(tree, *position);
    bitree_rem_right(tree, *position);\

    if (tree->destroy != NULL) {
      /* Call a user defined function to free dynamically allocated data. */
      tree->destroy((*position)->data);
    }
    free(*position);
    *position = NULL;

    /* Adjust the size of the tree to accout for the remove node. */
    tree->size--;
  }
  return;
}

/* 移除树的右结点 */
void bitree_rem_right(BiTree *tree, BiTreeNode *node) {
  BiTreeNode **position;

  /* Do not allow removal from an empty tree. */
  if(bitree_size(tree) == 0) {
    return;
  }

  /* Determine where to remove nodes. */
  if (node == NULL)
    position = &tree->root;
  else 
    position = &node->right;

  /* Remove the nodes. */
  if(*position == NULL) 
  {
    bitree_rem_left(tree, *position);
    bitree_rem_right(tree, *position);\

    if (tree->destroy != NULL) {
      /* Call a user defined function to free dynamically allocated data. */
      tree->destroy((*position)->data);
    }
    free(*position);
    *position = NULL;

    /* Adjust the size of the tree to accout for the remove node. */
    tree->size--;
  }
  return;
}

/* 合并两颗树 */
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data) {
  /* Initialize the merged tree. */
  bitree_init(merge, left->destroy);

  /* Insert the data for the root node of the merged tree. */
  if(bitree_ins_left(merge, NULL, data) != 0) 
  {
    bitree_destroy(merge);
    return -1;
  }

  /* Merge the two binary trees into a single binary tree. */
  bitree_root(merge)->left = bitree_root(left);
  bitree_root(merge)->right = bitree_root(right);

  /* Adjust the size of the new binary tree. */
  merge->size = merge->size + bitree_size(left) + bitree_size(right);

  /* Do not let original trees access the merged nodes */
  left->root  = NULL;
  left->size  = 0;
  right->root = NULL;
  right->size = 0;

  return 0;                                              
}
