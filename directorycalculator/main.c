#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right; 
} TreeNode;

int calc_dir_size(TreeNode* root)
{
    if(root == NULL) 
        return 0; // 공집합이면 0 반환
        
    int left = calc_dir_size(root->left);
    int right = calc_dir_size(root->right);
    
    return root->data + left + right;
}

TreeNode n6 = { 200, NULL, NULL };
TreeNode n7 = { 500, NULL, NULL };
TreeNode n3 = { 100, &n6, &n7 };
TreeNode n2 = { 50, NULL, NULL };
TreeNode n1 = { 0, &n2, &n3 };
    
int main(void)
{
    printf("디렉토리 크기 = %d\n", calc_dir_size(&n1));
}