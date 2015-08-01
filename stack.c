#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

typedef struct Stack Stack;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, int item)
{
    if(isFull(stack))
        printf("\n\nStack overflow\n");
    else
        stack->array[++stack->top] = item;
}

void pop(Stack* stack)
{
    if(isEmpty(stack)) {
        printf("\n\nStack underflow\n");
    }
    else
        printf("\nElement popped: %d", stack->array[stack->top--]);
}

void display(Stack* stack)
{
    int i;
    for(i = 0; i <= stack->top; i++) {
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}

int main(void)
{
    Stack* stack = createStack(100);

    int n, x;

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
                pop(stack);
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
}