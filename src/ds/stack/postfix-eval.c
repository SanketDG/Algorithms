#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int evaluatePostfix(char* exp)
{
    Stack* stack = createStack(strlen(exp));
    int i;

    if(!stack)
        printf("Failed to initialize stack."); // check to stack if created successfully
        exit(-1);
    for(i=0; exp[i] != '\0' ; ++i)
    {
        if(isdigit(exp[i]))
        {
            push(stack, exp[i] - '0');
        }
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch(exp[i])
            {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char exp[100];
    printf("Enter the postfix expression to be evaluated:\n");
    scanf("%s", exp);
    printf ("Value of expression %s is %d\n", exp, evaluatePostfix(exp));
    return 0;
}