#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType* l)
{
    l->size = 0;
}

int is_empty(ArrayListType* l)
{
    return l->size == 0;
}

int is_full(ArrayListType* l)
{
    return l->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* l, int pos)
{
    if(pos < 0 || pos >= l->size)
        error("POS ERROR");
    
    return l->array[pos];
}

void print_list(ArrayListType* l)
{
    for(int i = 0; i < l->size; i++)
        printf("%d->", l->array[i]);
    printf("\n");
}

void insert_last(ArrayListType* l, element data)
{
    if(is_full(l))
        error("LIST IS FULL");
    
    l->array[l->size++] = data;
}

void insert(ArrayListType* l, int pos, int item)
{
    if(!is_full(l) && pos >= 0 && pos <= l->size)
    {
        for(int i = l->size - 1; i >= pos; i--) // 가장 마지막 요소에서 부터 pos요소까지 순서대로 오른쪽으로 옮긴다. 
        {
            l->array[i + 1] = l->array[i]; 
        }
        
        l->array[pos] = item;
        l->size++;
    }
}

element delete(ArrayListType* l, int pos)
{
    element item;
    if(!is_empty(l) && pos >= 0 && pos < l->size)
    {
        item = l->array[pos];
        for(int i = pos; i < l->size - 1; i++) // pos요소 부터 size - 1 까지 왼쪽으로 옮긴다. 
        {
            l->array[i] = l->array[i+1];
        }
        
        l->size--;
    }
    
    return item;
}

int main(void)
{
    ArrayListType list;
    init(&list);
    
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    insert(&list, 4, 50); print_list(&list);
    insert(&list, 3, 60); print_list(&list);
    delete(&list, 2); print_list(&list);
    delete(&list, 3); print_list(&list);
}