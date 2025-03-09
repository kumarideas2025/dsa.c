#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}
void adaptedbubbleSort(int A[], int n) // for this out would take less pass cause it will not count the sorted passes
{
    int tem;
    int issort = 0;
    for (int i = 0; i < n - 1; i++)
    {                                              // for passes in array and n-1 we use cause index start from 0
        printf("working on the pass %d\n", i + 1); // we i+1 cause i start from 0 so we count pass for 1 and we count size (n-1).so for equal theme we use this
        issort = 1;                                // if is sort then spot here
        for (int j = 0; j < n - 1 - i; j++)        // if not then it will go there
        {                                          // for compair in every pass
            if (A[j] > A[j + 1])
            {
                tem = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tem;
                issort = 0;
            }
        }
        if (issort)
        {
            return;
        }
    }
}
void bubbleSort(int A[], int n) // but for this out will take size=10 .so it will take 10 pass to do the worh
{
    int tem;

    for (int i = 0; i < n - 1; i++)
    { // for passes in array and n-1 we use cause index start from 0
        printf("working on the pass %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        { // for compair in every pass
            if (A[j] > A[j + 1])
            {
                tem = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tem;
            }
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 6, 12, 54, 65, 7, 23, 9};
    int n = 10;
    printArray(A, n); // print before Sortting
    bubbleSort(A, n);
    adaptedbubbleSort(A, n);
    printArray(A, n); // print after Sorting
    return 0;
}