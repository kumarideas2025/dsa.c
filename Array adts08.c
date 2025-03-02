
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *prev;
   struct node *next;


};

void traverse1(struct node *ptr)
{
  while(ptr!=NULL)
     {
       printf("%d ",ptr->data);
       ptr=ptr->next;
   }
}
void traverse2(struct node *ptr)
{
  while(ptr!=NULL)
     {
       printf("%d ",ptr->data);
       ptr=ptr->prev;
   
   }
}

void traverse1(struct node *ptr);
void traverse2(struct node *ptr);
int main()
{
   struct node *first,*second,*third,*fourth;
   first=(struct node*)malloc(sizeof(struct node));
   second=(struct node*)malloc(sizeof(struct node));
   third=(struct node*)malloc(sizeof(struct node));
   fourth=(struct node*)malloc(sizeof(struct node));
   first->data=4;
   first->next=second;
   first->prev=NULL;
   second->data=6;
   second->next=third;
   second->prev=first;
   third->data=8;
   third->next=fourth;
   third->prev=second;
   fourth->data=7;
   fourth->next=NULL;
   fourth->prev=third;
   traverse1(first);
   printf("\nreverse traverse\n");
   traverse2(fourth);
   
 return 0;
}

