#include<stdio.h>
#include<stdlib.h>

    struct circularqueue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct circularqueue *q){
    if(((q->r+1)%q->size)==q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct circularqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int dequeue(struct circularqueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
void enqueue(struct circularqueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueue element: %d\n", val);
    }
}
int main(){
    struct circularqueue q;
    q.size = 4;
    // HERE WE DENOTE 0 CAUSE WE COUNT F=0; SO ONE POSITION IN THE INDEX WILL BE RESERVED
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size * sizeof(int));


    // (((((if we comment out 1st isempty part then it will not show cause we already store some elements)))))  also for 1st empty part output show empty cause at that time we did not pusp any element in it.....

    if (isEmpty(&q)) {
      printf("The Queue is empty\n");
    }


    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 15);
    



//for 2nd time if we type queue is empty then it will be not shown......

 if (isEmpty(&q)) {
        printf("The Queue is empty\n");
    }



    //((((if we want to check the queue is full or not )))   >>>>> output: will show nothing empty or full cause we already store some elements<<<<<<<<

    if (isFull(&q)) {
        printf("The Queue is full\n");
    }



    printf("\n");

    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    

    enqueue(&q,1);
    enqueue(&q,1);
    enqueue(&q,1);
    
    // {{{{we can check by using size of queue is full or not}}}}}}
    if (isEmpty(&q)) {
        printf("The Queue is empty\n");
    }


    if (isFull(&q)) {
        printf("The Queue is full\n");
    }

 return 0;

}