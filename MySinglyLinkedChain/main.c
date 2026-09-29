#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head; // head는 데이터나 링크 필드를 가지지 않는 단순 리스트에서 첫 번째 ListNode 타입을 가리키는 포인터 변수다!
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
	if(head == NULL)
		return NULL;

	ListNode* removed;
	removed = head;
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

void get_entry(ListNode* head, int index)
{
    int i = 0;
    ListNode* l;
    
    l = head;
    
    while(1)
    {
        if(i == index)
            break;
        else{
            l = l->link;
            i++;
        }
    }
    
    printf("%d번 노드의 값은: %d\n", index, l->data);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    ListNode* head = NULL;
    
    for(int i = 0; i < 10; i++)
    {
        head = insert_first(head, (rand() % 100) + 1);
        print_list(head);
    }
    
    for(int i = 0; i < 10; i++)
    {
        get_entry(head, i);
    }
    
    for(int i = 0; i < 10; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    
    return 0;
}