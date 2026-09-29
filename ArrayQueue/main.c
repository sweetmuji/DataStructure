#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q)
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType* q)
{
    for(int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if(i <= q->front || i > q->rear) // 예외 처리
            printf(" | ");
        else 
            printf("%d | ", q->data[i]); // 요소 출력
    }
    printf("\n");
}

int is_full(QueueType* q)
{
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int is_empty(QueueType* q)
{
    return q->rear == q->front;
}

void enqueue(QueueType* q, element item)
{
    if(is_full(q)) 
        error("QUEUE IS FULL!");
        
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q)
{
    if(is_empty(q))
        error("QUEUE IS EMPTY!");
        
    return q->data[++(q->front)];
}

int main(void)
{
    QueueType q;
    init_queue(&q);
    
    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 15); queue_print(&q);
    enqueue(&q, 21); queue_print(&q);
    enqueue(&q, 13); queue_print(&q);
    
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
}