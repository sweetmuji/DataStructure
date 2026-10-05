#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    char data;
} TreeNode;

void preorder_traversal(TreeNode* root) // 전위 순회 VLR
{
    if(root == NULL) 
        return;
        
    printf("%c-> ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(TreeNode* root) // 중위 순회 LVR
{
    if(root == NULL)
        return;
        
    inorder_traversal(root->left);
    printf("%c-> ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(TreeNode* root) // 후위 순회 LRV
{
    if(root == NULL)
        return;
    
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%c-> ", root->data);
}

int main(void)
{
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode)); n1->data = 'a';
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode)); n2->data = 'b';
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode)); n3->data = 'c';
    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode)); n4->data = 'd';
    TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode)); n5->data = 'e';
    TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode)); n6->data = 'f';
    TreeNode* n8 = (TreeNode*)malloc(sizeof(TreeNode)); n8->data = 'g';
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = NULL;
    n4->left = n8;
    n4->right = NULL;
    n5->left = NULL;
    n5->right = NULL;
    n6->left = NULL;
    n6->right = NULL;
    n8->left = NULL;
    n8->right = NULL;
    
    /*
                    a
                b       c
            d   e   f
        g
    */
    
    printf("\n========== 전위 순회 VLR ==========\n");
    preorder_traversal(n1);
    
    printf("\n========== 중위 순회 LVR ==========\n");
    inorder_traversal(n1);

    printf("\n========== 후위 순회 LRV ==========\n");
    postorder_traversal(n1);
    
    return 0;
}