#include "tree.h"




int main(void)
{

    tree_t *h = NULL;

    tree_create(&h);
    
    printf("前序遍历为:   ");
    tree_preorder_traverse(h);
    printf("\n");

    printf("中序遍历为:   ");
    tree_inorder_traverse(h);
    printf("\n");

    printf("后序遍历为:   ");
    tree_postorder_traverse(h);
    printf("\n");

    printf("二叉树的深度为：  %d\n", tree_depth(h));

    tree_destroy(h);

    return 0;
}
