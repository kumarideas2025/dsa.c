#include<stdio.h>
#include<stdlib.h>
// make it global varriable caus we want to use it in all the functions otherwise locsl functioon will cange it
struct node*f=NULL;
struct node*r=NULL;

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node*ptr){
    printf("traversing the linked list\n");
    while(ptr != NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("queue is full");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}
//((((((())))))) dequeue didnot take any argument cause we want to delete at the first and global variable is used((((((()))))))
int dequeue(){
    int val=-1;
    struct node*ptr=f;
    if(f==NULL){
        printf("queue is empty");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){

    linkedlisttraversal(f);
    //(((((printf("dequeued element is %d\n",dequeue()); output: it will return -1 .cause ther is nothing in the queue))))))))
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    linkedlisttraversal(f);
    printf("dequeued element is %d\n",dequeue());
    printf("dequeued element is %d\n",dequeue());
    linkedlisttraversal(f);
    return 0;
}