#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
    int top;
    int capacity; // 현재 배열의 사용할 크기를 나타내는 변수
    
    element* data; // 스택 배열의 시작 지점
} StackType;

void print_stack(StackType* s)
{
    for(int i = 0; i <= s->top; i++)
    {
        if(i == s->top)
            printf("%d(top)\n", s->data[i]);
        else if(i == 0)
            printf("%d(bottom) -> ", s->data[i]);
        else
            printf("%d -> ", s->data[i]);
    }
}
 
void init_stack(StackType* s)
{
    s->top = -1;
    s->capacity = 1;
    
    s->data = (element*)malloc(s->capacity * sizeof(element)); // 메모리 할당 후 시작 지점 주소 전달
}

int is_full(StackType* s)
{
    return s->top == s->capacity - 1;
}

int is_empty(StackType* s)
{
    return s->top == -1;
}

void push(StackType* s, element item)
{
    if(is_full(s))
    {
        printf("THE STACK IS FULL! REALLOCATING MEMORY...\n");
        s->capacity *= 2; // 만약 꽉 찼다면 배열 크기를 두 배로
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    
    s->data[++s->top] = item;
    print_stack(s);
}

element pop(StackType* s)
{
    if(is_empty(s))
    {
        printf("THE STACK IS EMPTY! POP DENIED.\n");
        return -1; 
    }
    
    return s->data[s->top--];
}

int main(void)
{
    StackType stack;
    init_stack(&stack);
    
    push(&stack, 3);
    push(&stack, 7);
    push(&stack, 1);
    push(&stack, 4);
    push(&stack, 9);
    push(&stack, 2);
    push(&stack, 5);
    push(&stack, 1);
    push(&stack, 7);
    push(&stack, 8);
    push(&stack, 3);
    push(&stack, 9);
    push(&stack, 0);
    push(&stack, 1);
    
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    
    
    free(stack.data);
    
    return 0;
}