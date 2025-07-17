#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *makenode(int data)
{
    struct node *n; 
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inOrder(struct node*root){
    if(root!=NULL){
         inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
        

    }
}
int main()
{


    struct node *p = makenode(4);
    struct node *p1 = makenode(1);
    struct node *p2 = makenode(6);
    struct node *p3 = makenode(5);
    struct node *p4 = makenode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

inOrder(p);
    

    return 0;
}