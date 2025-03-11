#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}
void insertionsort(int A[], int n)
{ // loop for passes
    int key, j;

    for (int i = 1; i <= n - 1; i++)
    {
        printf("working on pass %d\n",i+1);
        // loop for each passes
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        { // for asending order use A[j]>key output=7 9 12 23 54 65
            //for dsending order use A[j]<key output= 65 54 23 12 9 7
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; // this for index=-1.so we cannot go there 
    }
}
int main()
{
    //-1 0 1 2 3 4 5
    //  12 54 65  | 7 23 9 [<<< f0r A[j>key , so A[j+1]=A[j]>>>]
    //  12 54 7 65 23 9
    //  12 7 54 65 23 9
    //  7 12 54 65 23 9
    //  7 12 54 65 23 9
    // 7 9 12 23 54 65

    // j-- so j value is decrease( from j=3 to j=2 ) when A[j]>key .

    //-1  0   1  2  3   4    5 
    //   12  54  65  7   23   9---> i=1, key=54,j=0
    //   12 | 54  65  7   23   9 ---> 1st pass done(i=1)
    //   12  54 | 65  7   23   9---->  key=65,j=1,i=2 2nd pass done
    //   12  54  65 | 7   23   9---->j=2,i=3,key=7 .
    //   12  54  65 | 65   23   9---->as i<j,so i=3 and j=1,key=7
    //   12   54   54 | 65  23   9---> key 7,j=0
    //   12   12 54 | 65 23 9---> j=-1 .   A[j]>0 is false now so, loop will break and key will put on A[j+1] or (0+1) position
    //   7 12 54  |65 23 9----> 3rd pASS DONE

    //   7  12  54  65 | 23  9--->i=4,j=3
    //   7   12  54  65  65 9 --->i=4,j=2
    //   7  12 54 54 65 9---> i=4,j=2
    //   7  12 23 54 65 9---> i=4,j=2 .4th pass.

    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    insertionsort(A, n);
    printArray(A,n);
    return 0;
}