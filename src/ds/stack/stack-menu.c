#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    Stack* stack = createStack(100);

    int n, x, popped;

    printf("===STACK PROGRAM===\n");

    while(1)
    {
        printf("\n\nOperations:\n1. Push\n2. Pop\n3. Display\n4.Exit\nEnter operation: ");
        scanf("%d", &x);

        switch(x) {
            case 1: {
                printf("\nEnter element to push: ");
                scanf("%d", &n);
                push(stack, n);
                break;
            }
            case 2: {
                popped = pop(stack);
                if (popped != -1) {
                    printf("\nElement popped: %d", popped);
                }
                break;
            }
            case 3: {
                printf("\n\nStack --> ");
                display(stack);
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