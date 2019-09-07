#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
//Always remember why we are using the double pointer for head references
void push(struct Node** head_ref, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
int getCount(struct Node *head)
{
    int count = 0;
    struct Node* current = head;
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int main()
{
    struct Node* header = NULL;
    push(&header, 2);
    push(&header, 7);
    push(&header, 11);
    push(&header, 1);
    printf("The number of nodes here will be = %i", getCount(header));
}
