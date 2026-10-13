#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<assert.h>
#include "bst.h"

BST *bst_new()
{
    BST *bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->mass = 0;
    return bst;
}

static TreeNode *new_node(uint32_t data)
{
    TreeNode *tnode = (TreeNode*)malloc(sizeof(TreeNode));
    tnode->data = data;
    tnode->left = NULL;
    tnode->right = NULL;
    return tnode;
}


BST *bst_add(BST *bst, uint32_t key)
{
    TreeNode *parent;
    TreeNode *root;
    root = bst->root;
    parent = bst->root;

    while(root!=NULL && root->data != key)
    {
        parent = root;

        if(key < root->data)
        {
            root =root->left;
        }
        else if(key > root->data)
        {
            root = root->right;
        }  
    }

    if(root == NULL)
    {
        TreeNode *tnode = new_node(key);

        if(parent == NULL)
        {
            bst->root = tnode;
        }
        else if(key < parent->data)
        {
            parent -> left = tnode;
        }
        else if(key > parent->data)
        {
            parent -> right = tnode;
        }
        ++bst -> mass;
    }
    return bst;
}


uint32_t bst_find(BST *bst, uint32_t key)
{
    TreeNode *root = bst->root;

    while(root != NULL)
    {
        if(key < root->data)
        {
            root = root->left;
        }
        else if(key > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return(root!=NULL);
}


uint32_t bst_mass(BST *bst)
{
    return bst->mass;
}

uint32_t _height(TreeNode *root)
{
    uint32_t height, lheight, rheight;

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        lheight = _height(root->left);
        rheight = _height(root->right);

        if(lheight > rheight)
        {
            height = lheight + 1;
        }
        else
        {
            height = rheight + 1;
        }
        return height;
    }
}

//wrapper function
uint32_t bst_height(BST *bst)
{
    return _height(bst->root);
}



TreeNode *bst_delete(TreeNode *root, uint32_t key)
{
TreeNode *temp;

if(root == NULL)
{
    return NULL;
}

if(key < root->data)
{
    root -> left = bst_delete(root->left, key);
}
else if(key > root->data)
{
    root -> right = bst_delete(root -> right, key);
}

else
{
    if(root -> left == NULL)
    {
        temp = root -> right;
        free(root);
        return temp;
    }

    else if(root -> right == NULL)
    {
        temp = root -> left;
        free(root);
        return temp;
    }

     else
        {
            temp = root->right;

            /* Find the smallest node in the right subtree */
            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            /* Copy the successor's data */
            root->data = temp->data;

            /* Delete the successor node */
            root->right = bst_delete(root->right, temp->data);
        }
    }
    
    return root;
}

BST *bst_delete_node(BST *bst, uint32_t key)
{
    bst -> root = bst_delete(bst -> root, key);

    return bst;
}



//Inorder

void bst_inorder(TreeNode *root)
{
    if(root != NULL)
    {
        bst_inorder(root -> left);
        printf("%d", root -> data);
        bst_inorder(root -> right);
    }
}

BST *bst_inorder_traversal(BST *bst)
{
    bst_inorder(bst -> root);
    return bst;
}

//preorder

void bst_preorder(TreeNode *root)
{
    if(root != NULL)
    {
        printf("%d", root -> data);
        bst_preorder(root -> left);
        bst_preorder(root -> right);
    }
}

BST *bst_preorder_travesrsal(BST *bst)
{
    bst_preorder(bst -> root);
    return bst;
}

//postorder

void bst_postorder(TreeNode *root)
{
    if(root != NULL)
    {
        bst_postorder(root -> left);
        bst_postorder(root -> right);
        printf("%d", root -> data);
    }
}

BST *bst_postorder_traversal(BST *bst)
{
    bst_postorder(bst -> root);
    return bst;
}


