#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front, * rear;
} LinkedQueueType;

void init_queue(LinkedQueueType* q)
{
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q)
{
    return q->front == NULL;
}

void enqueue(LinkedQueueType* q, element data)
{
    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
    
    if(p == NULL) {
        printf("MEMORY IS FULL!!\n");
        exit(1);
    }
    
    p->data = data;
    p->link = NULL;
    
    if(is_empty(q)) {
        q->front = p;
        q->rear = p;
    }
    else {
        q->rear->link = p;
        q->rear = p;
    }
}

element dequeue(LinkedQueueType* q)
{
    if(is_empty(q)) {
        printf("QUEUE IS EMPTY!!\n");
        exit(1);
    }
    
    QueueNode* p = q->front;
    element value = p->data;
    
    q->front = p->link; 
    
    if(q->front == NULL) {
        q->rear = NULL; // front가 NULL이 되면 공백이므로 rear도 NULL을 가리키게 한다. 
    }
    
    free(p);
    
    return value;
}

void print_queue(LinkedQueueType* q)
{
    QueueNode* p = q->front;
    
    for(;p != NULL;p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(void) {
    LinkedQueueType queue;
    
    init_queue(&queue);
    
    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    
    return 0;
}