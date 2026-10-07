#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode n1 = { 3, NULL, NULL };
TreeNode n2 = { 2, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 10, NULL, NULL };
TreeNode n5 = { 2, NULL, NULL };
TreeNode n6 = { '/', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;

int evaulate(TreeNode* root)
{
    if(root == NULL) // 빈 노드면 0 반환
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) // 단말 노드일 때 ( 피연산자 )
    {
        return root->data;
    }
    else // 비 단말 노드일 때 ( 연산자 )
    {
        int op1 = evaulate(root->left); // L
        int op2 = evaulate(root->right); // R
        printf("%d %c %d 를 계산합니다...\n", op1, root->data, op2);
        switch (root->data) { // V 순회
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
        }
    }
}

int main(void)
{
    printf("%d\n", evaulate(exp));
}