#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int max(int a, int b)
{
    if(a>=b)
        return a;
    else 
        return b;
}

int get_tree_height(TreeNode* root)
{
    if (root == NULL)
        return 0;
        
    return 1 + max(get_tree_height(root->left), get_tree_height(root->right));
}

TreeNode n21 = { NULL, NULL };
TreeNode n10 = { NULL, &n21 };
TreeNode n5 = { &n10, NULL };
TreeNode n4 = { NULL, NULL };
TreeNode n7 = { NULL, NULL };
TreeNode n2 = { &n4, &n5 };
TreeNode n3 = { NULL, &n7 };
TreeNode n1 = { &n2, &n3 };

int main(void)
{
    printf("트리의 높이는 = %d\n", get_tree_height(&n1));
}