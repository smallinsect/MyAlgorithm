
#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode{
	int key;
	_TreeNode *p, *left, *right;
} TreeNode, *LPTreeNode;

void PREORDER_TREE_WALK(LPTreeNode x);//前序遍历
void INORDER_TREE_WALK(LPTreeNode x);//中序遍历
void POSTORDER_TREE_WALK(LPTreeNode x);//后续遍历

LPTreeNode TREE_SEARCH(LPTreeNode x, int key);//查找
LPTreeNode ITERATIVE_TREE_SEARCH(LPTreeNode x, int key);//迭代查询

LPTreeNode TREE_MINIMUM(LPTreeNode x);//最小元素
LPTreeNode TREE_MAXIMUM(LPTreeNode x);//最大元素

LPTreeNode TREE_SUCCESSOR(LPTreeNode x);//后继
LPTreeNode TREE_PREDECESSOR(LPTreeNode x);//前驱

void TREE_INSERT(LPTreeNode &T, LPTreeNode z);//插入
void TREE_DELETE(LPTreeNode &T, LPTreeNode z);//删除
void TRANSPLANT(LPTreeNode &T, LPTreeNode u, LPTreeNode v);//v替换u

void testTree();

#endif
