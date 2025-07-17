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
    while(root!=NULL){
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        root=root->left;
    }
    else{
        root=root->right;
    }
    
}
return NULL;
}

void insert(   struct node* root,  int key){
struct node* prev=NULL;
while(root!=NULL){
    prev=root;
if(key==root->data){
    printf("cannot insert %d in BST already have in bst ",key);
    return;
}

else if(key<root->data){
    root=root->left;
}

else{
    root=root->right;
}
}
struct node*new=makenode(key);
if(key< prev->data){
    prev->left=new;
}
else{
    prev->right=new;
}

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

    insert(p,6);
    printf("%d",p->right->right->data);
    return 0;
}


 