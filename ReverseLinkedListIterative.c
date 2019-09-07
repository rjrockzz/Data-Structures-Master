//codιng вloĸe
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
static void reverse(struct Node** head_ref) {
    struct Node *prev = NULL, *current=*head_ref , *next = NULL;
    while(current!=((void*)0))
    {
        next = current->next;
        current->next = prev;
        prev = current; //prev will get shifted to the right
        current = next;
    }*head_ref=prev;
}
void push(struct Node** head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void printer(struct Node* head)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct Node* header = NULL;
    push(&header, 1);
    push(&header, 2);
    push(&header, 3);
    push(&header, 4);
    push(&header, 5);
    printf("The normal linked list was = ");
    printer(header);
    reverse(&header);
    printf("\nThe reversed linked list is = ");
    printer(header);
}
