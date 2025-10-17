#include <stdio.h>

void swap(int *a, int *b);
void display(int *A, int n);
void quickSort(int *A, int low, int high);

int partition(int *A, int low, int high)
{
    int pivot = A[high];  // Choose last element as pivot
    int i = low - 1;      // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i + 1], &A[high]);
    return (i + 1);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);

        quickSort(A, low, pi - 1);  // Sort left part
        quickSort(A, pi + 1, high); // Sort right part
    }
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

    quickSort(A, 0, n - 1);
    printf("After sorting: \n");
    display(A, n);

    return 0;
}