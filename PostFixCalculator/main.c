#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    
    int top;
} StackType;

void initStack(StackType* s)
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

void push(StackType* s, element data)
{
    if(is_stack_full(s)) {
        printf("STACK_IS_FULL! RETURNING...\n");
        return;
    }
    
    s->data[++s->top] = data;
}

element pop(StackType* s)
{
    if(is_stack_empty(s)) {
        printf("STACK IS EMPTY! EXITTING...\n");
        exit(1);
    }
    
    return s->data[s->top--];
}

element peek(StackType* s)
{
    if(is_stack_empty(s)) {
        printf("STACK IS EMPTY! EXITTING...\n");
        exit(1);
    }
    
    return s->data[s->top];
}

int PostFixCalculator(char* s)
{
    StackType operands; // 피연산자들을 담을 스택
    initStack(&operands);
    
    for(int i = 0; i < strlen(s); i++) // 입력된 후위 표기식 문자열을 순회한다. 
    {
        char input = s[i]; // 현재의 문자열을 담을 문자 변수 
        
        element op1, op2; // 피연산자 두 개
        
        switch(input)
        {
            case '+':
                op2 = pop(&operands);
                op1 = pop(&operands); // "op1 (연산자) op2" 계산을 위해 변수에 pop해서 대입. 
                push(&operands, (op1 + op2));
                break;
            case '-':
                op2 = pop(&operands);
                op1 = pop(&operands); // "op1 (연산자) op2" 계산을 위해 변수에 pop해서 대입. 
                push(&operands, (op1 - op2));
                break;
            case '*':
                op2 = pop(&operands);
                op1 = pop(&operands); // "op1 (연산자) op2" 계산을 위해 변수에 pop해서 대입. 
                push(&operands, (op1 * op2));
                break;
            case '/':
                op2 = pop(&operands);
                op1 = pop(&operands); // "op1 (연산자) op2" 계산을 위해 변수에 pop해서 대입. 
                push(&operands, (op1 / op2));
                break;
            default:
                push(&operands, input - '0'); // 피연산자면 push
                break;
        }
    }
    
    return pop(&operands); // 마지막으로 남아있는 값 반환
}

int getPriority(char op) // 연산자를 받아서 우선순위를 반환하는 함수
{
    switch(op)
    {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case ')':  
            return 0;
        default:
            return -1;
    }
}

// 피연산자를 만나면 그대로 출력한다. 연산자를 만난다면 스택에 넣고, 다음 연산자를 만난다면 우선순위를 비교 후 높은 것을 출력
// 열린 괄호면 일단 push ( 괄호 안, 밖 연산을 분리하기 위해 ) 하고 닫는 괄호를 만나면 열린괄호를 만날 때 까지 pop.
void infixToPostFix(char* infix, char* postfix)
{
    StackType operands; // 피연산자들을 저장할 스택
    initStack(&operands);
    
    int postFixArrayIndex = 0; // 후위표기식 문자열 배열에서의 인덱스 번호
    for(int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];
        char top_op;
        switch(ch)
        {
            case '+': // 연산자라면 
            case '-':
            case '*':
            case '/': // 스택이 비어있지 않거나 우선 순위가 높은 연산자들을 모두 출력할 때 까지 후위표기식에 입력
                while(!is_stack_empty(&operands) && (getPriority(ch) <= getPriority(peek(&operands)))) 
                {
                    postfix[postFixArrayIndex++] = pop(&operands);   
                }
                push(&operands, ch); // 우선 순위가 높거나 같은 연산자를 모두 후위표기식에 입력한 후 연산자를 스택에 push
                break;
            case '(':  
                push(&operands, ch); // 열린 괄호라면 일단 push 하여 기존 연산과 분리
                break;
            case ')':  
                top_op = pop(&operands);
                while(top_op != '(') // 열린 괄호를 만날 때 까지 pop
                {
                    postfix[postFixArrayIndex++] = top_op;
                    top_op = pop(&operands);
                }
                break;
            default: // 피연산자라면 
                postfix[postFixArrayIndex++] = ch;
                break;
        }
    }
    
    while(!is_stack_empty(&operands))
    {
        postfix[postFixArrayIndex++] = pop(&operands);
    }
    
    postfix[postFixArrayIndex] = '\0'; // 문장의 끝(Null) 지정
}

int main(void)
{
    char inFixString[100];
    char postFixString[100];
    
    printf("후위표기식으로 변환하고싶은 중위표기식을 입력하세요:");
    scanf("%s", inFixString);
    infixToPostFix(inFixString, postFixString);
    printf("%s -> %s\n", inFixString, postFixString);
    printf("후위 표기식의 계산 값은: %d\n", PostFixCalculator(postFixString));
}
