#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *createnew(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

struct node *mergetwo(struct node *list1, struct node *list2)
{
    struct node temp;
    struct node *New = &temp;
    temp.next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            New->next = list1;
            list1 = list1->next;
        }
        else
        {
            New->next = list2;
            list2 = list2->next;
        }
        New=New->next;
    }
    if (list1 != NULL)
    {
        New->next = list1;
    }
    else
    {
        New->next = list2;
    }

    return temp.next;
}
void printlist(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *list1 = createnew(3);
    list1->next = createnew(5);
    list1->next->next = createnew(7);

    struct node *list2 = createnew(2);
    list2->next = createnew(4);
    list2->next->next = createnew(6);

    struct node *merge = mergetwo(list1, list2);
    printf("merged list is:");
    printlist(merge);
    return 0;
}