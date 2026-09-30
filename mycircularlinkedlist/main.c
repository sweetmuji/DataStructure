#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data; // 데이터 필드 
    struct ListNode* link; // 링크 필드
} ListNode;

void print_list(ListNode* head)
{
    if(head == NULL) {
        return;
    }
    
    ListNode* p = head->link; // 첫 노드를 가리킨다.

    do {
        printf("%d->", p->data);
        p = p->link;
    } while(p!=head->link);
    
    printf("\n");
}

void free_list(ListNode* head)
{
    if(head == NULL)
        return; 
        
    ListNode* p = head->link; // 첫 노드를 가리킨다.
    ListNode* temp; // 임시로 head주소를 백업할 포인터
    
    do {
        temp = p->link; // 다음 노드 저장
        free(p); 
        p = temp;
    } while(p!=head);
    
    free(head);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    
    if(head == NULL) // 만약 빈 원형 연결 리스트라면
    {
        head = node;
        node->link = head; // 첫 노드이자 마지막 노드가 된다.
    }
    else
    {
        node->link = head->link; // 새로운 첫 번째 노드가 기존의 첫 번째 노드를 향하게
        head->link = node; // 마지막 노드가 새로운 첫 번째 노드를 향하게
    }
    
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    
    if(head == NULL) // 만약 빈 원형 연결 리스트라면
    {
        head = node;
        node->link = node; // 첫 노드이자 마지막 노드가 된다.
    }
    else
    {
        node->link = head->link; // 새로운 노드가 기존의 끝 노드를 가리킨다.
        head->link = node; // 기존의 끝 노드가 새로운 끝 노드를 가리킨다.
        head = node; // 헤드 포인터가 새로운 끝 노드를 가리킨다. 
    }
    
    return head;
}

int main(void)
{
    ListNode* head = NULL;
    
    head = insert_first(head, 10); print_list(head);
    head = insert_last(head, 20); print_list(head);
    head = insert_last(head, 30); print_list(head);
    head = insert_last(head, 40); print_list(head);
    
    free_list(head); 
    
    return 0;
}