#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _tree_t{
    int data;               //数据域
    struct _tree_t *lchild; //左孩子指针
    struct _tree_t *rchild; //右孩子指针

}tree_t;

int tree_create(tree_t **t);


//树的前序遍历
void tree_preorder_traverse(tree_t *root);

//二叉树的中序遍历
void tree_inorder_traverse(tree_t *root);

//二叉树的后序遍历
void tree_postorder_traverse(tree_t *root);

//二叉树的深度
int tree_depth(tree_t *root);


//二叉树的销毁
int tree_destroy(tree_t *root);

#endif /*__TREE_H__*/
