//@coding bloke
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
//Post Order
void postorder(struct node* node)
{
    if(node==NULL)
        return;
    //left subtree
    postorder(node->left);
    //right subtree
    postorder(node->right);
    printf("%d ", node->data);
}
//In Order
void inorder(struct node* node)
{
    if(node==NULL)
        return;
    //left subtree
    inorder(node->left);
    printf("%d ", node->data);
    //right subtree
    inorder(node->right);
}
void preorder(struct node* node)
{
    if(node==NULL)
        return;
    printf("%d ", node->data);
    //left subtree
    preorder(node->left);
    //right subtree
    preorder(node->right);
}
int main()
{
    struct node* root = newnode(25);
    root->left = newnode(15);
    root->left->left = newnode(10);
    root->left->left->left = newnode(4);
    root->left->left->right = newnode(12);
    root->left->right = newnode(22);
    root->left->right->left = newnode(18);
    root->left->right->right = newnode(24);
    root->right = newnode(50);
    root->right->left = newnode(35);
    root->right->left->left = newnode(31);
    root->right->left->right = newnode(44);
    root->right->right = newnode(70);
    root->right->right->left = newnode(66);
    root->right->right->right = newnode(90);
    printf("\nPreorder traversal of binary tree is \n");
    preorder(root);

    printf("\nInorder traversal of binary tree is \n");
    inorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    postorder(root);

    getchar();
    return 0;
}