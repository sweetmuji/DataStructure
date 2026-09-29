#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_SIZE];
    int top;
} StackType;

int is_full(StackType* s)
{
    return s->top == MAX_SIZE - 1;
}

int is_empty(StackType* s)
{
    return s->top == -1;
}

void init_stack(StackType* s)
{
    s->top = -1; // 스택을 초기화
}

void print_stack(StackType* s)
{
    if(s->top == -1)
    {
        printf("스택이 완전히 비었습니다.\n");
        return;
    }
    
    for(int i = 0; i <= s->top; i++)
    {
        if(i == s->top)
            printf("%d\n", s->data[i]);
        else
            printf("%d ->", s->data[i]);
    }
}

void push(StackType* s, element item)
{
    if(is_full(s))
    {
        printf("STACK IS FULL\n");
        return;
    }
    
    printf("스택에 %d를 push합니다.\n", item);
    s->data[++s->top] = item;
    print_stack(s);
}

element pop(StackType* s)
{
    if(is_empty(s))
    {
        printf("STACK IS EMPTY\n");
        return -1;
    }
    
    printf("스택에서 %d를 pop합니다.\n", s->data[s->top]);
    
    return s->data[s->top--];
}

int main(void)
{
    StackType stack;
    init_stack(&stack);
    
    push(&stack, 1);
    push(&stack, 7);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    print_stack(&stack);
    print_stack(&stack);
    print_stack(&stack);
}