#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;                                                     // Represents initialization of the Stack's top to -1 or EMPTY
    stack->array = (int*)malloc(stack->capacity*(sizeof(int)));          //Array defined to store the stack elements
    return stack;
}
int isFull(struct Stack* stack)
{
        return stack->top==stack->capacity-1;   //Thus returns 0 ,its no true but if returns 1 ,
                                                // that means the condition is true hence stack is full, therefore exit (see return in the push)
}
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;                      //Thus returns 0 ,its no true but if returns 1 ,
                                                // that means the condition is true hence stack is empty, therefore exit (see return in the pop)
}
void push(struct Stack* stack , int item)
{
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int returningTop(struct Stack* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
};
int main()
{
    struct Stack* stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("\n%d popped from stack", pop(stack));
    printf("\n%d popped from stack", pop(stack));
    printf("\n%d popped from stack", pop(stack));
    printf("\n%d popped from stack", pop(stack));   //value of INT_MIN will be printed out
    return 0;
}