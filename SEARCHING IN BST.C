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

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }

    else if (key < root->data)
    {
        return search(root->left, key);
    }

    else
    {
        return search(root->right, key);
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

    int m;
    printf("enter the number:");
    scanf("%d", &m);
// we make this pointer to point the nodes
    struct node *n = search(p, m);
    if (n != NULL)
    {
        printf("found:%d", n->data);
    }

    else
    {
        printf("elemnet not found");
    }
    return 0;
}