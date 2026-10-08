#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int get_leaf_count(TreeNode* root)
{
    if(root == NULL) // 공집합 노드일 경우
        return 0;
        
    if(root->left == NULL && root->right == NULL) // 단말 노드일 경우
        return 1;
    else
        return get_leaf_count(root->left) + get_leaf_count(root->right); // 비단말 노드일 경우
}

TreeNode n8 = { NULL, NULL };
TreeNode n9 = { NULL, NULL };
TreeNode n4 = { &n8, &n9 };
TreeNode n5 = { NULL, NULL };
TreeNode n2 = { &n4, &n5 };
TreeNode n3 = { NULL, NULL };
TreeNode n1 = { &n2, &n3 };

int main(void)
{
    printf("노드의 단말 노드 개수는 %d 입니다.\n", get_leaf_count(&n1));
    
    return 0;
}