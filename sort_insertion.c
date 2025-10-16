#include <stdio.h>

void display(int *A, int n);
void insertionSort(int *A, int n);

void insertionSort(int *A, int n)
{
    int key, j;
    //Loop for passes
    for (int i = 0; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        //Loop for each passes
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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

    insertionSort(A, n);
    printf("After sorting: \n");
    display(A, n);

    return 0;
}