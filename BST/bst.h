#include <stdint.h>

typedef struct _treenode_ TreeNode;
typedef struct _bst_ BST;

struct _treenode_{
    uint32_t data;
    TreeNode *left;
    TreeNode *right;
};

struct _bst_{
    TreeNode *root;
    uint32_t mass;
};

BST *bst_new();
BST *bst_add(BST *tree,uint32_t key);
uint32_t bst_find(BST *bst, uint32_t key);
uint32_t bst_mass(BST *bst);
uint32_t bst_height(BST *bst);
BST *bst_delete_node(BST *bst, uint32_t key);

void bst_inorder(TreeNode *root);
BST *bst_inorder_traversal(BST *bst);

void bst_preorder(TreeNode *root);
BST *bst_preorder_travesrsal(BST *bst);

void bst_postorder(TreeNode *root);
BST *bst_postorder_traversal(BST *bst);


