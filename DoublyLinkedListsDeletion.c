//@codιng вloĸe
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void push(struct Node **head_ref, int data )
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if(*head_ref != ((void*)0))
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}
void Deletion(struct Node **head_ref, struct Node* del)
{
    //Shew! An empty list!
    if(*head_ref == NULL || del == NULL)
        return;
    //if the deleted node is header node itself
    if(*head_ref == del)
        *head_ref = del->next;
    //Change next if node to be deleted is NOT the last
    if(del->next != NULL)
        del->next->prev = del->prev;
    //Change prev if node to be deleted is n=NOT the first
    if(del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}
void printList(struct Node *node)
{
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Let us create the doubly linked list 10<->8<->4<->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("\n Original Linked list ");
    printList(head);

    /* delete nodes from the doubly linked list */
    Deletion(&head, head); /*delete first node*/
    Deletion(&head, head->next); /*delete middle node*/
    Deletion(&head, head->next); /*delete last node*/

    /* Modified linked list will be NULL<-8->NULL */
    printf("\n Modified Linked list ");
    printList(head);
    printf("\n %d\t\t%d", head->next,head->prev);

    getchar();
}