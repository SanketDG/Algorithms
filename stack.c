#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
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
