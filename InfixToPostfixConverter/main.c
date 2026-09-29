#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    int top;
    element data[MAX_STACK_SIZE];
} StackType;
 
void init_stack(StackType* s)
{
    s->top = -1;
}

int is_stack_full(StackType* s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

int is_stack_empty(StackType* s)
{
    return s->top == -1;
}

void push(StackType* s, element item)
{
    if(is_stack_full(s))
    {
        printf("STACK IS FULL\n");
        exit(1);
    }
    
    s->data[++s->top] = item;
}

element pop(StackType* s)
{
    if(is_stack_empty(s))
    {
        printf("STACK IS EMPTY\n");
        exit(1);
    }
    
    return s->data[s->top--];
}

element peek(StackType* s)
{
     if(is_stack_empty(s))
    {
        printf("STACK IS EMPTY\n");
        exit(1);
    }
    
    return s->data[s->top]; 
}

int operatorWeightReturner(char c) // 연산자의 우선 순위를 리턴하는 함수. 
{
    switch(c)
    {
        case '(':
        case ')':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            return 3;
            break;
    }
}

void InfixToPostfixConverter(char* input)
{
    StackType operatorStack;
    init_stack(&operatorStack);
    
    for(int i = 0; i < strlen(input); i++)
    {
        char op = input[i];
        
        switch(op)
        {
            case '(': // 열린 괄호라면 무조건 푸쉬 ( 괄호 안의 수식을 독립적으로 계산. )
                push(&operatorStack, op);
                break;
            case '+':
            case '-':
            case '*':
            case '/': // 스택에 있는 연산자가 우선순위가 더 높다면 출력
                while(!is_stack_empty(&operatorStack) && ((operatorWeightReturner(op) <= operatorWeightReturner(peek(&operatorStack)))))
                    printf("%c", pop(&operatorStack));
                push(&operatorStack, op); // 스택에 있는 우선 순위가 더 높은 연산자를 모두 출력한 뒤 push
                break; 
            case ')': // 닫힌 괄호를 만난다면 열린 괄호를 만날 때 까지 출력
                char topOp = pop(&operatorStack);
                while(topOp != '(')
                {
                    printf("%c", topOp);
                    topOp = pop(&operatorStack);
                }
                break;
            default: // 피연산자는 그대로 출력
                printf("%c", op);
        }
    }
    
    while(!is_stack_empty(&operatorStack))
    {
        printf("%c", pop(&operatorStack));
    }
}

int main(void)
{
    char *s;
    
    printf("수식 문자열을 입력하세요:");
    scanf("%s", s);
    
    printf("Infix = %s\n", s);
    printf("Postfix = ");
    InfixToPostfixConverter(s);
    
    return 1;
}