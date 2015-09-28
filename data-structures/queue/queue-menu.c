#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    Queue* queue = createQueue(100);

    int n, x, dequeued;

    printf("===QUEUE PROGRAM===\n");

    while(1)
    {
        printf("\n\nOperations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter operation: ");
        scanf("%d", &x);

        switch(x) {
            case 1: {
                printf("\nEnter element to enqueue: ");
                scanf("%d", &n);
                enqueue(queue, n);
                break;
            }
            case 2: {
                dequeued = dequeue(queue);
                if (dequeued != INT_MIN) {
                    printf("\nElement dequeued: %d", dequeued);
                }
                break;
            }
            case 3: {
                printf("\n\nQueue --> ");
                display(queue);
                break;
            }
            case 4: {
                exit(0);
                break;
            }
            default : printf("Invalid Input\n");
        }
    }

    return 0;
}