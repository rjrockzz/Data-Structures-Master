//@codιng вloĸe
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// function to get a new node
struct Node* getNode(int data)
{
    // allocate memory for node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));

    // put in the data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse the circular linked list
void reverse(struct Node** head_ref)
{
    // if list is empty
    if (*head_ref == NULL)
        return;

    // reverse procedure same as reversing a
    // singly linked list
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref));

    // adjutsing the links so as to make the
    // last node point to the first node
    (*head_ref)->next = prev;
    *head_ref = prev;
}

// Function to print circular linked list
void printList(struct Node* head)
{
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Driver program to test above
int main()
{
    // Create a circular linked list
    // 1->2->3->4->1
    struct Node* head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(3);
    head->next->next->next = getNode(4);
    head->next->next->next->next = head;

    printf("Given List is: ");
    printList(head);

    reverse(&head);

    printf("\nThe reversed list is: ");
    printList(head);

    return 0;
} 