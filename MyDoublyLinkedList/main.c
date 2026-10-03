#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    struct DListNode* llink;
    element data;
    struct DListNode* rlink;
} DListNode;



void dinsert(DListNode* before, element data)
{
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = data;
    
    node->rlink = before->rlink;
    node->llink = before;
    before->rlink->llink = node;
    before->rlink = node;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if(removed == head)
        return;
    
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    
    free(removed);
}

