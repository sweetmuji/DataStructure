#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
    int front;
    int rear;
    
    element data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_queue_full(QueueType* q)
{
   return q->front == (q->rear + 1) % MAX_QUEUE_SIZE; 
}

int is_queue_empty(QueueType* q)
{
    return q->front == q->rear;
}

void enqueue(QueueType* q, element data)
{
    if(is_queue_full(q)) {
        printf("QUEUE IS FULL! QUITTING...\n");
        exit(1);
    }
    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; 
    q->data[q->rear] = data;
}

element dequeue(QueueType* q)
{
    if(is_queue_empty(q)) {
        printf("QUEUE IS EMPTY! QUITTING...\n");
        exit(1);
    }
    
    element data;
    data = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    
    return data;
}

void print_queue(QueueType* q)
{
    if(!is_queue_empty(q))
    {
        printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
        int i = q->front; // 프론트 + 1부터 리어까지 연산해서 출력
        do {
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%d |", q->data[i]);
            
            if(i == q->rear) // 리어까지 출력하고 종료
                break;
                
        } while(i != q->front);
    }
    
    printf("\n");
}

int main(void)
{
    QueueType queue;
    init_queue(&queue);
    element input;
    
    printf("\n========== 데이터 추가 단계 ==========\n");
    
    while(!is_queue_full(&queue))
    {
        printf("입력할 정수 입력:");
        scanf("%d", &input);
        enqueue(&queue, input);
        print_queue(&queue);
    }
    
    printf("\n!- 큐가 포화 상태임\n");
    printf("\n========== 데이터 삭제 단계 ==========\n");
    
    while(!is_queue_empty(&queue))
    {
        input = dequeue(&queue);
        printf("dequeue = %d\n", input);
        print_queue(&queue);
    }
    
    printf("\n!- 큐가 공백 상태임\n");
    
    return 0;
}
