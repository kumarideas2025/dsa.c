#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n");
}
void bubbleSort(int A[], int n)
{
    int tem;

    for (int i = 0; i < n - 1; i++)
    { // for passes in array and n-1 we use cause index start from 0

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
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n); // print before Sortting
    bubbleSort(A, n);
    printArray(A, n); // print after Sorting
    return 0;
}