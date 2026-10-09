#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* search_recursion(TreeNode* root, int key) // BST 탐색 순환
{
    if(root == NULL) return NULL;
    
    if(root->key == key)
        return root;
    else {
        if(key<=root->key) // 찾으려는 키 값이 현재 BST 노드 키 값 보다 작을 때
            return search_recursion(root->left, key);
        else // 클 때 
            return search_recursion(root->right, key);
    }
}

TreeNode* search_iteration(TreeNode* root, int key) // BST 탐색 반복 
{
    while(root!=NULL) {
        if(root->key == key)
            return root;
        else
            if(root->key >= key)
                root = root->left;
            else
                root = root->right;
    }
    
    return NULL;
}

TreeNode n14 = { 27, NULL, NULL };
TreeNode n4 = { 3, NULL, NULL };
TreeNode n5 = { 12, NULL, NULL };
TreeNode n7 = { 31, &n14, NULL };
TreeNode n2 = { 7, &n4, &n5 };
TreeNode n3 = { 26, NULL, &n7 };
TreeNode n1 = { 18, &n2, &n3 };

int main(void)
{
    printf("순환적으로 노드를 탐색합니다...\n");
    printf("%d = %d\n", 18, search_recursion(&n1, 18)->key);
    printf("%d = %d\n", 7, search_recursion(&n1, 7)->key);
    printf("%d = %d\n", 26, search_recursion(&n1, 26)->key);
    printf("%d = %d\n", 3, search_recursion(&n1, 3)->key);
    printf("%d = %d\n", 12, search_recursion(&n1, 12)->key);
    printf("%d = %d\n", 31, search_recursion(&n1, 31)->key);
    printf("%d = %d\n", 27, search_recursion(&n1, 27)->key);
    
    printf("반복적으로 노드를 탐색합니다...\n");
    printf("%d = %d\n", 18, search_iteration(&n1, 18)->key);
    printf("%d = %d\n", 7, search_iteration(&n1, 7)->key);
    printf("%d = %d\n", 26, search_iteration(&n1, 26)->key);
    printf("%d = %d\n", 3, search_iteration(&n1, 3)->key);
    printf("%d = %d\n", 12, search_iteration(&n1, 12)->key);
    printf("%d = %d\n", 31, search_iteration(&n1, 31)->key);
    printf("%d = %d\n", 27, search_iteration(&n1, 27)->key);
    
    return 0;
}

