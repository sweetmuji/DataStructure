#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    struct DListNode* llink;
    struct DListNode* rlink;
    element data;
} DListNode;

void init_list(DListNode* head)
{
    head->rlink = head;
    head->llink = head;
}

void dinsert(DListNode* pre, element data)
{
    DListNode* p = (DListNode*)malloc(sizeof(DListNode));
        
    if(p == NULL) {
        printf("MEMORY ERROR!!\n");
        exit(1);
    }
    
    p->data = data;
    p->rlink = pre->rlink;
    p->llink = pre;
    pre->rlink->llink = p;
    pre->rlink = p;
}

void ddelete(DListNode* removed, DListNode* head)
{
    if(removed == head) {
        return;
    }
    
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    
    free(removed);
}

void print_node_reverse(DListNode* head) // 연결리스트를 역순으로 출력하는 함수
{
    if(head->rlink == head)
        return; 
        
    DListNode* p = head->llink; // 마지막 노드
    
    printf("데이터를 역순으로 출력: ");
    do {
        printf("%d<- ", p->data);
        p = p->llink;
    } while(p!=head);
    printf("\n");
}

void print_node(DListNode* head)
{
    if(head->rlink == head)
        return;
        
    DListNode* p = head->rlink;
    
    printf("데이터를 출력: ");
    do {
        printf("%d-> ", p->data);
        p = p->rlink;
    } while(p!=head);
    printf("\n");
}

DListNode* search(DListNode* head, element data)
{
    DListNode* p = head->rlink; // 첫 노드 대입
    
    do {
        if(p->data == data)
            return p;
        else 
            p = p->rlink;
    } while(p!=head);
    
    return NULL;
}

int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init_list(head);
    
    printf("========== 데이터 입력 단계 ==========\n");
    for(int i = 0; i < 3; i++) {
        dinsert(head, i); 
        print_node(head);
    }
    
    print_node_reverse(head);
    
    printf("========== 탐색 단계 ==========\n");
    for(int i = -2; i < 5; i++) {
        DListNode* p = search(head, i);
        
        if(p == NULL) {
            printf("이중 연결 리스트에는 %d(이)가 없습니다.\n", i);
        }
        else {
            printf("이중 연결 리스트에 %d(이)가 존재합니다! p->data = %d\n", i, p->data);
        }
    }
}