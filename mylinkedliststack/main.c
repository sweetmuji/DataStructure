#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

void init_stack(LinkedStackType* s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
    return s->top == NULL;
}

void push(LinkedStackType* s, element data)
{
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    
    if(p == NULL) {
        printf("MEMORY IS FULL!!\n");
        return;
    }
    
    p->data = data;
    p->link = s->top;
    s->top = p;
}

element pop(LinkedStackType* s)
{
    if(is_empty(s)) {
        printf("STACK IS EMPTY!!\n");
        exit(1);
    }
    
    StackNode* p = s->top;
    element value = p->data;
    s->top = p->link;
    free(p);
    
    return value;
}

element peek(LinkedStackType* s)
{
    if(is_empty(s)) {
        printf("STACK IS EMPTY!!\n");
        exit(1);
    }
    
    return s->top->data;
}

void print_stack(LinkedStackType* s)
{
    for(StackNode* p = s->top; p!=NULL; p = p->link) {
        printf("%d ->", p->data);
    }
    printf("NULL \n");
}

int main(void)
{
    LinkedStackType s;
    init_stack(&s);
    
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    
    return 0;
}