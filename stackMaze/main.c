#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
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
    s->data[++s->top] = item;
}

element pop(StackType* s)
{
    return s->data[s->top--];
}

element peek(StackType* s)
{
    return s->data[s->top];
}

element currentPos;
element startPos = { 1, 0 };

char MAZE[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1'},
    { 'e', '0', '1', '0', '0', '1'},
    { '1', '0', '0', '0', '1', '1'},
    { '1', '0', '1', '0', '1', 'x'},
    { '1', '0', '1', '0', '0', '0'},
    { '1', '1', '1', '1', '1', '1'}
};

void push_Pos(StackType* s, short r, short c)
{
    if(r < 0 || c < 0) // 범위를 벗어나면 리턴
        return;
        
    if(MAZE[r][c] != '1' && MAZE[r][c] != '.') // 막다른 곳이 아니고 지나온 길이 아니라면 push
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        
        push(s, tmp);
    }
}

void maze_printf(char maze[MAZE_SIZE][MAZE_SIZE])
{
    for(int i = 0; i < MAZE_SIZE; i++)
    {
        for(int j = 0; j < MAZE_SIZE; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void maze_search()
{
    StackType posStack;
    init_stack(&posStack);
    
    currentPos = startPos; // 시작 지점 초기화
    while(MAZE[currentPos.r][currentPos.c] != 'x') // 출구에 도달할 때 까지 검색
    {
        MAZE[currentPos.r][currentPos.c] = '.'; // 현재 위치 한 좌표 . 표시 ( 지나온 길을 표시하기 위해 )
        // currentPos 에서 상 하 좌 우 순으로 탐색 한 뒤 push
        
        maze_printf(MAZE);
        
        push_Pos(&posStack, currentPos.r + 1, currentPos.c);
        push_Pos(&posStack, currentPos.r - 1, currentPos.c);
        push_Pos(&posStack, currentPos.r, currentPos.c - 1);
        push_Pos(&posStack, currentPos.r, currentPos.c + 1);
        
        if(is_stack_empty(&posStack)) {
            printf("FAILED TO FIND THE EXIT! QUITTING...\n");
            exit(1);
        }
        
        currentPos = pop(&posStack);
    }
}

int main(void)
{
    maze_search();
}