#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s)
{
    s->top = -1;
}

int is_full(StackType* s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

int is_empty(StackType* s)
{
    return s->top == -1;
}

void push(StackType* s, element c)
{
    if(is_full(s))
        return;
        
    s->data[++s->top] = c;
}

element pop(StackType* s)
{
    if(is_empty(s))
        exit(1);
        
    return s->data[s->top--];
}

void print_stack(StackType* s)
{
    for(int i = 0; i <= s->top; i++)
    {
        if(i == s->top)
            printf("%d\n", s->data[i]);
        else
            printf("%d -> ", s->data[i]);
    }
}

int CheckParenthesisMatching(char* input)
{
    StackType s;
    init_stack(&s);
    
    char c, opench;
    int length = strlen(input);
    
    for(int i = 0; i < length; i++)
    {
        c = input[i];
        switch(c) {
            case '(':
            case '{':
            case '[':
                push(&s, c);
                break;
            case ')':
            case '}':
            case ']':
                if(is_empty(&s)) // 스택이 비어있을 때. 즉, 열린 괄호가 없을 때 즉시 0 반환. 
                    return 0;
                else {
                    opench = pop(&s);
                    if((opench == '(' && c != ')') || (opench == '{' && c != '}') || (opench == '[' && c != ']'))
                        return 0;
                }
                break;
        }
    }
    
    if(!is_empty(&s))
        return 0;
        
    return 1;
}

int main(void)
{
    int result;
    char input[100];
    printf("괄호를 검사할 수식을 입력하세요:");
    scanf("%s", &input);
    
    result = CheckParenthesisMatching(input);
    
    if(result)
        printf("수식의 괄호 배치에 문제가 없습니다.\n");
    else
        printf("수식의 괄호 배치에 문제가 있습니다.\n");
    
    return 0;
}
