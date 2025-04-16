#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*create(int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insertATend(struct node**head,int data){
struct node*ptr=create(data);
if(*head==NULL){
    *head= ptr;
    return;
}
struct node*temp=*head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=NULL;
}

int searching( struct node*head, int key){
    struct node*p=head;
    while(p!=NULL){
        if(p->data==key){
            return 1;
        }
        p=p->next;
    }
    return 0;
}
 
void printlist(struct node*ptr){
    while(ptr!=NULL){
        printf("elements are :%d\n",ptr->data);
        ptr=ptr->next;

    }
    printf("NULL\n");
}

int main (){
    struct node*head=NULL;
    insertATend(&head,3);
    insertATend(&head,7);
    insertATend(&head,9);
    insertATend(&head,10);
printlist(head);
int key=3;
if(searching(head,key)){
    printf("value found at %d\n",key);
}
else{
    printf("value is not found:%d\n",key);
}
return 0;
}