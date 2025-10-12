//element insertion & delete in stack using array
#include<stdio.h>

void push(int *);
void pop(void);
void display(int *);

int tos=-1;
int ele;
int n;

void push(int *ptr)
{
    printf("Enter the element which you want to insert: ");
    scanf(" %d",&ele);
    if(tos==n-1)
      printf("Stack overflow");
    else
       ptr[++tos]=ele;
}

void pop(void)
{
    if(tos==-1)
    printf("Stack underflow");
    else
    printf("After deletion\n");
    tos--;
}

void display(int *ptr)
{
    if(tos==-1)
    {
        printf("Stack is empty");
        return;
    }
    
    printf("Stack elements (bottom to top): ");
    for (int i =0; i <= tos; i++)
        printf(" %d ",ptr[i]);
        printf("\n");
}

int main()
{
    printf("Enter the no of elements in stack: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the value of tos: ");
    scanf(" %d",&tos);

     if (tos >= n || tos < -1)
    {
        printf("Invalid tos value! Should be between -1 and %d\n", n - 1);
        return 1;
    }

    printf("Enter %d elements: ",tos+1);
    for(int i=0;i<=tos;i++)
    scanf(" %d",&a[i]);
    display(a);
    push(a);
    display(a);
    pop();
    display(a);
    return 0;
}