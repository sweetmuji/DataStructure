#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void my_BST_insert(TreeNode* root, int key, TreeNode* parent)
{
    if(root == NULL) {
        TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
        newnode->key = key;
        newnode->left = newnode->right = NULL;
        
        if(parent->key > key)
            parent->left = newnode;
        else
            parent->right = newnode;
        
        return;
    }
    
    if(root->key == key) {
        printf("이미 트리에 %d가 존재합니다.\n", key);
        return;
    }
    else if(root->key > key) 
        BST_insert(root->left, key, root);
    else if(root->key < key)
        BST_insert(root->right, key, root);
}

TreeNode* new_node(int key)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = key;
    temp->left = temp->right = NULL;
    
    return temp;
}

TreeNode* BST_insert(TreeNode* node, int key)
{
    if(node == NULL)
        return new_node(key);
    
    if(key < node->key)
        node->left = BST_insert(node->left, key);
    else if (key > node->key)
        node->right = BST_insert(node->right, key);
    
    return node;
}