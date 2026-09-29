#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef; // 계수
    int expon; // 지수
    
    struct ListNode* link; // 링크 필드
} ListNode; 

typedef struct ListType {
    int size;
    ListNode* head; // 첫 노드를 가리키는 멤버 포인터 
    ListNode* tail; // 마지막 노드를 가리키는 멤버 포인터
} ListType; // 헤드 노드 타입

ListType* create()
{
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    
    return plist;
}

void insert_last(ListType* plist, int coef, int expon)
{
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    
    if(temp == NULL)
    {
        printf("메모리 초과 오류!!");
        exit(1);
    }
    
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    
    if(plist->tail == NULL) // 끝 노드가 비어있으므로 노드가 비어있는 것으로 판단.
    {
        plist->head = plist->tail = temp;
    }
    else // 노드가 비어있지 않고 기존의 노드에 추가할 때.
    {
        plist->tail->link = temp; // 기존 끝 노드가 새로운 끝 노드를 가리키게 하고..
        plist->tail = temp; // 기존 끝 노드를 새로운 노드로 설정. 
    }
    
    plist->size++; // 리스트 사이즈 증가
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum = 0;
    
    while(a!=NULL && b!=NULL) // a와 b가 모두 NULL이 아닐 때 까지
    {
        if(a->expon > b->expon)
        {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else if(a->expon < b->expon)
        {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
        else
        {
            sum = a->coef + b->coef;
            if(sum!=0)
                insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
    }
    
    for(; a!=NULL; a=a->link)
    {
        insert_last(plist3, a->coef, a->expon);
    }
    for(; b!=NULL; b=b->link)
    {
        insert_last(plist3, b->coef, b->expon);
    }
}

void poly_print(ListType* plist)
{
    ListNode* p = plist->head;
    
    printf("polynomial = ");
    for(;p!=NULL; p=p->link) {
        if(p->link == NULL)
            if(p->expon == 0)
                printf("%d", p->coef);
            else
                printf("%d^%d", p->coef, p->expon);
        else
            printf("%d^%d + ", p->coef, p->expon);
    }
    
    printf("\n");
}

int main(void)
{
    ListType* list1, * list2, * list3;
    
    list1 = create();
    list2 = create();
    list3 = create();
    
    insert_last(list1, 3, 12);
    insert_last(list1, 3, 10);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);
    
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);
    
    poly_print(list1);
    poly_print(list2);
    
    poly_add(list1, list2, list3);
    poly_print(list3);
    
    free(list1);
    free(list2);
    free(list3);
    
    return 0;
}