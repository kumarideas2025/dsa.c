#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *makenode(int data)
{
    struct node *n; // making a node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{

    // for root node
    // struct node*p;
    // p=(struct node*)malloc(sizeof(struct node));
    // p->data=2;
    // p->left=NULL;
    // p->right=NULL;
    // return 0;

    // //for 1st node
    // struct node*p1;
    // p1=(struct node*)malloc(sizeof(struct node));
    // p->data=1;
    // p1->left=NULL;
    // p1->right=NULL;
    // return 0;

    // //for 2nd node
    // struct node*p2;
    // p2=(struct node*)malloc(sizeof(struct node));
    // p->data=4;
    // p2->left=NULL;
    // p2->right=NULL;
    // return 0;

    // //linked right and left node with children
    // p->left=p1;
    // p->right=p2;

    struct node *p = makenode(2);
    struct node *p1 = makenode(1);
    struct node *p2 = makenode(4);

    p->left = p1;
    p->right = p2;



    

    return 0;
}