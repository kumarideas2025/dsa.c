#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        
    }
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // bFS implementation
    int node;
    int i = 0; // if we i=1 .then otput will will 1023456
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {

        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}

    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q); // get 1 element and found the all connected element with it 
        for (int j = 0; j < 7; j++) // if we already visit then no needed to come in for loop
        {
            if (a[node][j] == 1 && visited[j] == 0)// exporation  but not visited
            {
                printf("%d", j);// 0,1,2,,4,5,6
                visited[j] = 1;                  //for visited all exporation element
                enqueue(&q, j);//0,1,2,3,4,5,6
            }
        }
    }

    return 0;
}