#include <stdio.h>

void swap(int *a, int *b);
void display(int *A, int n);
void bubbleSort(int *A, int n);

void bubbleSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of element of the array:\n");
    scanf("%d", &n);
    int A[n];
    printf("Enter the %d element: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Before sorting: \n");
    display(A, n);

    bubbleSort(A, n);
    printf("After sorting: \n");
    display(A, n);

    return 0;
}