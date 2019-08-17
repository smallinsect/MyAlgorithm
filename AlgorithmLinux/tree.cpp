
#include "tree.h"

void PREORDER_TREE_WALK(LPTreeNode x){//前序遍历
	if(x){
		printf("%d ", x->key);
		PREORDER_TREE_WALK(x->left);
		PREORDER_TREE_WALK(x->right);
	}
}

void INORDER_TREE_WALK(LPTreeNode x){//中序遍历
	if(x){
		INORDER_TREE_WALK(x->left);
		printf("%d ", x->key);
		INORDER_TREE_WALK(x->right);
	}
}

void POSTORDER_TREE_WALK(LPTreeNode x){//后续遍历
	if(x){
		POSTORDER_TREE_WALK(x->left);
		POSTORDER_TREE_WALK(x->right);
		printf("%d ", x->key);
	}
}

LPTreeNode TREE_SEARCH(LPTreeNode x, int key){//查找
	if(x == NULL || x->key == key){
		return x;
	}
	if(key < x->key){
		return TREE_SEARCH(x->left, key);
	}
	return TREE_SEARCH(x->right, key);
}

LPTreeNode ITERATIVE_TREE_SEARCH(LPTreeNode x, int key){//迭代查询
	while(x != NULL && x->key != key){
		if(key < x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	return x;
}

LPTreeNode TREE_MINIMUM(LPTreeNode x){//最小元素
	while(x->left != NULL){
		x = x->left;
	}
	return x;
}
LPTreeNode TREE_MAXIMUM(LPTreeNode x){//最大元素
	while(x->right != NULL){
		x = x->right;
	}
	return x;
}

LPTreeNode TREE_SUCCESSOR(LPTreeNode x){//后继
	if(x->right){
		return TREE_MINIMUM(x->right);
	}
	LPTreeNode y = x->p;
	while(y != NULL && y->right == x){
		x = y;
		y = x->p;
	}
	return y;
}
LPTreeNode TREE_PREDECESSOR(LPTreeNode x){//前驱
	if(x->left){
		return TREE_MAXIMUM(x->left);
	}
	LPTreeNode y = x->p;
	while(y != NULL && y->left == x){
		x = y;
		y = x->p;
	}
	return y;
}

void TREE_INSERT(LPTreeNode &T, LPTreeNode z){//插入
	LPTreeNode y = NULL;
	LPTreeNode x = T;
	while(x){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->p = y;
	if(y == NULL){
		T = z;
	}else if(z->key < y->key){
		y->left = z;
	}else{
		y->right = z;
	}
}
void TREE_DELETE(LPTreeNode &T, LPTreeNode z){//删除
	if(z->left == NULL){
		TRANSPLANT(T, z, z->right);
	}else if(z->right == NULL){
		TRANSPLANT(T, z, z->left);
	}else{
		LPTreeNode y = TREE_MINIMUM(z->right);
		if(z->right != y){
			TRANSPLANT(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		TRANSPLANT(T, z, y);
		y->left = z->left;
		y->left->p = y;
	}
}
void TRANSPLANT(LPTreeNode &T, LPTreeNode u, LPTreeNode v){//v替换u
	if(u->p == NULL){//u是根节点
		T = v;
	}else if(u->p->left == u){//u是父亲的左孩子
		u->p->left = v;
	}else{//u是父亲的有孩子
		u->p->right = v;
	}
	if(v != NULL){
		v->p = u->p;
	}
}

void TREE_FREE(LPTreeNode x){
	if(x != NULL){
		TREE_FREE(x->left);
		TREE_FREE(x->right);
		free(x);
	}
}

void testTree(){
	LPTreeNode T = NULL, x;
	int array[11] = {15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
	for(int i = 0; i < 11; ++i){
		x = (LPTreeNode)malloc(sizeof(TreeNode));
		x->key = array[i];
		x->p = x->left = x->right = NULL;
		TREE_INSERT(T, x);
	}
	PREORDER_TREE_WALK(T);
	printf("\n");

	x = TREE_SEARCH(T, 15);
	if(x){
		printf("查找成功\n");
		TREE_DELETE(T, x);
		free(x);
		PREORDER_TREE_WALK(T);
		printf("\n");
	}

	TREE_FREE(T);
}
