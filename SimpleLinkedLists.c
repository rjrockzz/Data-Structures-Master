#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main()
{
    //Initializing pointers to null
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    //Allocating memory to the pointers , here type of pointer is the node pointer
    //is the struct value
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;

    second->data = 3;
    second-> next = third;

    third-> data = 5;
    third ->next = NULL;

}