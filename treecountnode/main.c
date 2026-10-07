#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int get_node_count(TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    return 1 + get_node_count(root->left) + get_node_count(root->right);
}

TreeNode n14 = { NULL, NULL };
TreeNode n8 = { NULL, NULL };
TreeNode n9 = { NULL, NULL };
TreeNode n4 = { &n8, &n9 };
TreeNode n5 = { NULL, NULL };
TreeNode n7 = { &n14, NULL };
TreeNode n2 = { &n4, &n5 };
TreeNode n3 = { NULL, &n7 };
TreeNode n1 = { &n2, &n3 };

int main(void)
{
    printf("트리에서 노드의 총 개수는 = %d\n", get_node_count(&n1));
}

