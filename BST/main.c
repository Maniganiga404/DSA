#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

int main(void)
{
    BST *bst = bst_new();

    bst = bst_add(bst, 50);
    bst = bst_add(bst, 30);
    bst = bst_add(bst, 20);
    bst = bst_add(bst, 40);

    printf("Find 30: %d\n", bst_find(bst, 30));
    printf("Find 100: %d\n", bst_find(bst, 100));


    //mass
    printf("Mass: %d\n", bst_mass(bst));
    //height
    printf("Height: %d\n", bst_height(bst));

    //traversals
    printf("Inorder Traversal: ");
    bst_inorder_traversal(bst);


    printf("\nPreorder Traversal: ");
    bst_preorder_travesrsal(bst);

    printf("\nPostorder Traversal: ");
    bst_postorder_traversal(bst);
    printf("\n");

    //delete node

    bst = bst_delete_node(bst, 30);

    printf("Inorder after deleting 30: ");
    bst = bst_inorder_traversal(bst);
    printf("\n");


    free(bst);


    return 0;
}



