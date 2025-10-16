#include <stdio.h>

void swap(int *a, int *b);
void display(int *A, int n);
void selectionSort(int *A, int n);

void selectionSort(int *A, int n)
{
    int indexOfMin;
    printf("Running selection sorting...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        swap(&A[i], &A[indexOfMin]);
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

    selectionSort(A, n);
    printf("After sorting: \n");
    display(A, n);

    return 0;
}