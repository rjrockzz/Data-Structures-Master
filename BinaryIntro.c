#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};
struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
/*create root*/
int main()
{
    struct node *root = newnode(1);
/* following is the tree after above statement

      1
    /   \
   NULL  NULL
*/


root->left        = newnode(2);
root->right       = newnode(3);
/* 2 and 3 become left and right children of 1
         1
       /   \
      2      3
   /    \    /  \
  NULL NULL NULL NULL
*/


root->left->left  = newnode(4);
/* 4 becomes left child of 2
         1
     /       \
    2          3
  /   \       /  \
 4    NULL  NULL  NULL
/  \
NULL NULL
*/

return 0;
}