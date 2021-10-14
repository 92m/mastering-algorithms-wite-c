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

/* 初始化二叉树 */
void bitree_init(BiTree *tree, void (*destroy)(void *data));

/* 销毁二叉树 */  
void bitree_destroy(BiTree *tree);

/* 在指定树左结点插入元素结点 */
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);

/* 在指定树右结点插入元素结点 */
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);

/* 移除树的左结点 */
void bitree_rem_left(BiTree *tree, BiTreeNode *node);

/* 移除树的右结点 */
void bitree_rem_right(BiTree *tree, BiTreeNode *node);

/* 合并两颗树 */
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/* 查找指定树结点的数量 */
#define bitree_size(tree) ((tree)->size)

/* 查找指定树的根结点 */
#define bitree_root(tree)((tree)->root)

/* 判断是否为二叉树分支的末端 */
#define bitree_is_eob(node)((node) == NULL)

/* 判断指定结点是否为二叉树中的子结点 */
#define bitree_is_leaf(node)((node)->left == NULL && (node)->right ==NULL)

/* 返回指定结点中储存的数据 */
#define bitree_data(node)((node)->data)

/* 返回指定结点的左结点 */
#define bitree_left(node)((node)->left)

/* 返回指定结点的右结点 */
#define bitree_right(node)((node)->right)

#endif /* BITREE_C */