#include<stdio.h>
#include<stdlib.h>
struct Node
{
    void *data; //void pointer used to point to any kind of data
    struct Node *next;
};
void push(struct Node **head_ref, void *new_data, size_t data_size){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
    new_node->next = *head_ref;
    int i;
    for(i=0; i<data_size;i++)
        //copying contents of new_data to newly allocated memory
        *(char *)(new_node-> data + i) = *(char *)(new_data + i);
    *head_ref = new_node;
}
void printList(struct Node *node, void(*fptr)(void *))/*fptr is used
to access the function to be used for printing current node data.
Note that different data types need different specifier in printf() */
{
    while(node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}
void printInt(void *n)
{
    printf("%d " , *(int *)n);
}
void printFloat(void *f)
{
    printf("%f" , *(float *)f);
}
int main()
{
    struct Node *start = NULL;

    // Create and print an int linked list
    unsigned int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40, 50}, i;
    for (i=4; i>=0; i--)
        push(&start, &arr[i], int_size);
    printf("Created integer linked list is \n");
    printList(start, printInt);

    // Create and print a float linked list
    unsigned float_size = sizeof(float);
    start = NULL;
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    for (i=4; i>=0; i--)
        push(&start, &arr2[i], float_size);
    printf("\n\nCreated float linked list is \n");
    printList(start, printFloat);

    return 0;
}
