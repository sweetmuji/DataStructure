#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    
    return head;
}

ListNode* delete_first(ListNode* head)
{
    if (head == NULL) return NULL;
    
    ListNode* removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head)
{
    for(ListNode* p = head; p != NULL; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) // 요소 x 와 같은 값을 가지는 요소를 찾는 
{
    int i = 0;
    for(ListNode* p = head; p!=NULL; p=p->link)
    {
        if(p->data == x)
        {
            printf("리스트에서 %d를 찾았습니다. %d 번 노드에 위치해 있습니다.\n", x, i);
            return p;
        }
        
        i++;
    }
    
    printf("리스트에서 %d를 찾지 못하였습니다.\n", x);
    return NULL;
}

ListNode* concatenate_list(ListNode* head1, ListNode* head2)
{
    if(head1 == NULL) // head1 이 비어있으면 head2 만 반환
        return head2;
    else if(head2 == NULL) // head2 가 비어있으면 head1 만 반환
        return head1;
    else {
        ListNode* p;
        p = head1; // p를 head1 리스트의 시작 지점으로 초기화
        while(p->link != NULL) // 다음 노드가 NULL 이 아닐 때 까지. 즉, 마지막 노드까지 대입한다. 
            p = p->link;
        
        p->link = head2;
        return head1;
    }
}

int main(void)
{
    ListNode* head = NULL;
    
    for(int i = 10; i > 0; i--)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    
    ListNode* search_result;
    
    search_result = search_list(head, 4);
    search_result = search_list(head, 11);
    search_result = search_list(head, 1);
    search_result = search_list(head, 10);
    search_result = search_list(head, 8);
    
    ListNode* head2 = NULL;
    
    for(int i = 0; i < 5; i++)
    {
        head2 = insert_first(head2, i);
        print_list(head2);
    }
    
    concatenate_list(head, head2);
    print_list(head);
}