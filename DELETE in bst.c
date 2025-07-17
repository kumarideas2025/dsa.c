#include <stdio.h>
#include <stdlib.h>
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

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

int Isbst(struct node *root)
{

    static struct node *prev = NULL;
    if (root != NULL)
    {

        if (!Isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;

        return Isbst(root->right);
    }

    else
    {
        return 1;
    }
}

struct node *searchiTER(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}


struct node*inOrderPredecessor( struct node*root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}


struct node *DelNode(struct node *root, int value)
{
    struct node* iPre;
    // base condition of recursion
    if(root==NULL){
        return NULL;
    }
// if we find a leaf node then we have to free the root

    if((root->left==0 && root->right==0) && root->data==value ){
        free(root);
        return NULL;
    }

    // search for the node to be deleted
    if (value < root->data)
    {
        //root->left cause it will gave me a null so we can reconstruct it
       root->left= DelNode(root->left, value);
    }
    else if (value > root->data)
    {
       root->right= DelNode(root->right, value);
    }
    // deletion starting
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
       root->left  = DelNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *p = makenode(5);
    struct node *p1 = makenode(3);
    struct node *p2 = makenode(6);
    struct node *p3 = makenode(1);
    struct node *p4 = makenode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inOrder(p);
    DelNode(p,5);
    printf("\n");
    printf("data is %d",p->data);
    printf("\n");
    inOrder(p);

    return 0;
}



 