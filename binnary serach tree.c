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





// isbst is creat on a asending   inorder cause inorder return a  BST

int Isbst(struct node *root)
{
    // prev means   a parent  of child     ...as 1st root is the child ...it has Null in it prev(1st prev is null for 1st root ) but no null after that

    static struct node *prev = NULL;
    if (root != NULL)
    {

        // will be write in mimi of inorder ====> left - root - right


        

        // that part for left part of step
        // not isbst(root->left)  means left side of a root is not a bst return 0
        if (!Isbst(root->left))
        {
            return 0;
        }
        // root->data is grater than prev data ..if it then it will be bst
        // prev data is null for 1st root . so in 2nd root it cannot be null .so we write like this
        // it will not return n0. cause prev is null in 1st
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }




        // that part for root step
        // so 5 (root) will be make as prev
        prev = root;



        // that part for right part step
        return Isbst(root->right);
    }

    else
    {
        return 1;
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

    inOrder(p);
    printf("\n");
    if(Isbst(p)){
        printf("this is a bst");
    }
    return 0;
}