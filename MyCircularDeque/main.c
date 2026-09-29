#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct {
    int front;
    int rear;
    
    element data[MAX_QUEUE_SIZE];
} DequeType;

void init_deque(DequeType* q)
{
    q->front = q->rear = 0;
}

int is_full(DequeType* q)
{
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

int is_empty(DequeType* q)
{
    return q->front == q->rear;
}

void add_front(DequeType* q, element item)
{
    if(is_full(q)) {
        printf("error: THE DEQUE IS FULL!!\n");
        exit(1);
    }
    
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(DequeType* q, element item)
{
    if(is_full(q)) {
        printf("error: THE DEQUE IS FULL!!\n");
        exit(1);
    }
    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
    if(is_empty(q)) {
        printf("error: THE DEQUE IS EMPTY!!\n");
        exit(1);
    }
    
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(DequeType* q)
{
    if(is_empty(q)) {
        printf("error: THE DEQUE IS EMPTY!!\n");
        exit(1);
    }
    
    element i = q->data[q->rear];
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return i;
}

void print_deque(DequeType* q)
{
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d |", q->data[i]);
            
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}

int main(void)
{
    DequeType queue;
    init_deque(&queue);
    
    add_front(&queue, 1); print_deque(&queue);
    add_front(&queue, 2); print_deque(&queue);
    add_front(&queue, 3); print_deque(&queue);
    add_rear(&queue, 4); print_deque(&queue);
    add_rear(&queue, 5); print_deque(&queue);
    
    delete_front(&queue); print_deque(&queue);
    delete_rear(&queue); print_deque(&queue);
    delete_front(&queue); print_deque(&queue);
    delete_rear(&queue); print_deque(&queue);
    delete_rear(&queue); print_deque(&queue);
    
    return 0;
}