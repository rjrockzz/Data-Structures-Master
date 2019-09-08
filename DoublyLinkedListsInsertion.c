//@codιng вloĸe
#include<stdio.h>
#include<stdlib.h>
//Doubly Linked Lists
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
//Insertion in front
void push(struct Node **head_ref, int new_data)
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node-> data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if(*head_ref !=NULL)
        (*head_ref)->prev =new_node;
    *head_ref = new_node;
}
void insertAfter(struct Node* prev, int data)
{
    if(prev==((void*)0))
        printf("The previous cannot be null");
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    new_node->prev = prev;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void insertAtLast(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref==NULL){
        new_node->prev=((void*)0);
        *head_ref = new_node;
        return;
    }
    if(last->next!=NULL)
        last=last->next;
    last->next = new_node;
    new_node->next = ((void*)0);
    new_node->prev = last;
    return;
}
void printList(struct Node* node)
{
    printf("\nTraversal in forward direction \n");
    while (node->next != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    struct Node *last = node;
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
void main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    insertAtLast(&head, 6);

    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    insertAtLast(&head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    printf("Created DLL is: ");
    printList(head);

}
//Insertion before a given node follows the following approach
/*void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)
*{
//    /*1. check if the given next_node is NULL */
//if (next_node == NULL) {
//printf("the given next node cannot be NULL");
//return;
//}
//
///* 2. allocate new node */
//struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//
///* 3. put in the data */
//new_node->data = new_data;
//
///* 4. Make prev of new node as prev of next_node */
//new_node->prev = next_node->prev;
//
///* 5. Make the prev of next_node as new_node */
//next_node->prev = new_node;
//
///* 6. Make next_node as next of new_node */
//new_node->next = next_node;
//
///* 7. Change next of new_node's previous node */
//if (new_node->prev != NULL)
//new_node->prev->next = new_node;
///* 8. If the prev of new_node is NULL, it will be
//   the new head node */
//else
//(*head_ref) = new_node;
//
//}
//**/