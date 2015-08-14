typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
void pop(Stack* stack);
void display(Stack* stack);
