#include "tree.h"


//递归实现创建二叉树
int tree_create(tree_t **t)
{
    char ch;
    

    if (NULL == t)
        goto err0;

    
    scanf("%c", &ch); 
    
    //空  #代表没有孩子节点  节点为NULL
    if ('#' == ch)
    {
        *t = NULL;
    }
    else
    {
        //分配节点
        *t = malloc(sizeof(tree_t));  
        if (NULL == *t)
            goto err0;
        memset(*t, 0, sizeof(tree_t));

        //给数据域赋值
        (*t)->data = ch;  
        //递归创建左子树
        tree_create(&((*t)->lchild));
        //递归创建右子树
        tree_create(&((*t)->rchild));
    }

    return 0;
err0:
    return -1;
}


//树的前序遍历
//根 左 右
void tree_preorder_traverse(tree_t *root)
{
    if (NULL == root)
        return;

    printf("%c ", root->data);
    fflush(stdout);
    tree_preorder_traverse(root->lchild);
    tree_preorder_traverse(root->rchild);
}


//二叉树的中序遍历
//左 根 右
void tree_inorder_traverse(tree_t *root)
{
    if (NULL ==  root)
        return;

    tree_inorder_traverse(root->lchild);
    printf("%c ", root->data);
    tree_inorder_traverse(root->rchild);
}

//二叉树的后序遍历
//左 右 根
void tree_postorder_traverse(tree_t *root)
{
    if (NULL == root)
        return;

    tree_postorder_traverse(root->lchild);
    tree_postorder_traverse(root->rchild);
    printf("%c ", root->data);

}



//二叉树的深度
int tree_depth(tree_t *root)
{
    int depth;
    int max_r = 0;
    int max_l = 0;


    if (NULL == root->rchild && NULL == root->lchild)
        return 1;

    if (NULL != root->lchild)
        max_l = tree_depth(root->lchild);

    if (NULL != root->rchild)
        max_r = tree_depth(root->rchild);
    
    depth = max_r > max_l ? max_r : max_l;
    return depth + 1;
}

//二叉树的销毁
int tree_destroy(tree_t *root)
{
    if (NULL == root)
        goto err0;
    
    tree_destroy(root->lchild);
    tree_destroy(root->rchild);
    free(root);

    return 0;
err0:
    return -1;
}











