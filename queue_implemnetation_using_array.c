//Queue implementation using array

#include<stdio.h>

void push(int *);
void pop(void);
void display(int *);

int tos=-1;  
int ele;
int n;
int *arr;     

void push(int *ptr)
{
    printf("Enter the element which you want to insert: ");
    scanf("%d",&ele);
    if(tos==n-1)
        printf("Queue overflow\n");
    else {
        ptr[++tos] = ele;   
        printf("%d inserted into queue\n", ele);
    }
}

void pop(void)
{
    if(tos==-1)
        printf("Queue underflow\n");
    else {
        printf("Deleted element: %d\n", arr[0]);
        for(int i=0; i<tos; i++) {
            arr[i] = arr[i+1];   
        }
        tos--;
    }
}

void display(int *ptr)
{
    if(tos==-1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for(int i=0; i<=tos; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

int main()
{
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    int a[n];
    arr = a;   

    printf("Enter the initial rear (tos): ");
    scanf("%d",&tos);

    if(tos >= n || tos < -1) {
        printf("Invalid rear value! Should be between -1 and %d\n", n - 1);
        return 1;
    }

    if(tos >= 0) {
        printf("Enter %d elements: ", tos+1);
        for(int i=0; i<=tos; i++)
            scanf("%d",&a[i]);
    }

    display(a);
    push(a);
    display(a);
    pop();
    display(a);

    return 0;
}