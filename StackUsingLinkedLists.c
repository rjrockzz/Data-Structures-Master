#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int data;
    struct Stack* next;
};
struct Stack* new_node(int data)
{
    struct Stack *new_node = (struct Stack*) malloc(sizeof(struct Stack));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
int isEmpty(struct Stack* root)
{
    return !root;
}
void push(struct Stack** root, int data)
{
    struct Stack* stackNode = new_node(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
int pop(struct Stack ** root)
{
    if(isEmpty(root))
        return INT_MIN;
    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(struct Stack* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    struct Stack* root = NULL;

    push(&root, 10);
//    printf("\n***%d***\n", !root);
    push(&root, 20);
//    printf("\n***%d***\n", !root);
    push(&root, 30);
//    printf("\n***%d***\n", !root);

    printf("%d popped from stack\n", pop(&root));
//    printf("\n***%d***\n", !root);
    printf("%d popped from stack\n", pop(&root));
//    printf("\n***%d***\n", !root);
//    printf("%d popped from stack\n", pop(&root));
//    printf("\n***%d***\n", !root);
//    printf("%d popped from stack\n", pop(&root));
//    printf("\n***%d***\n", !root);
    printf("Top element is %d\n", peek(root));

    return 0;
}
