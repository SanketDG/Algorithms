#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int front, rear, size;
    int maxsize;
    int* array;
}Queue;

Queue* createQueue(int maxsize)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->maxsize = maxsize;
    queue->front = queue->size = 0;
    queue->rear = maxsize - 1;
    queue->array = (int*)malloc(queue->maxsize * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->maxsize);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        print("\nQueue Overflow\n");
    else {
        queue->rear = (queue->rear + 1) % queue->maxsize;
        queue->array[queue->rear] = item;
        queue->size = queue->size + 1;
    }
}

int dequeue(Queue* queue)
{
    if(isEmpty(queue)) {
        printf("\nQueue Underflow\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->maxsize;
    queue->size = queue->size - 1;
    return item;
}

