#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int front, rear, maxsize;
    int* array;
}Queue;

Queue* createQueue(int maxsize)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->maxsize = maxsize;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->maxsize * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->rear == queue->maxsize - 1);
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        printf("\nQueue Overflow\n");
    else {
        if ((queue->front == -1) && (queue->rear == -1))
            queue->front = 0;
        queue->array[++queue->rear] = item;
    }
}

int dequeue(Queue* queue)
{
    int item;
    if(isEmpty(queue)) {
        printf("\nQueue Underflow\n");
        return INT_MIN;
    }
    item = queue->array[queue->front];
    if(queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        queue->front++;
    return item;
}

void display(Queue* queue)
{
    int i;
    for(i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
}
