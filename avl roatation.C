#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getheight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node *createnode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getbalancefactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct Node *rightrotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return x;
}

struct Node *leftrotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)

        return createnode(key);
    if (key < node->key)

        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // for leaf we update use this code
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getbalancefactor(node);

    // left left
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    // right right
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // left right
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // right left
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{

    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}