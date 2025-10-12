//queue

#include<stdio.h>

void enqueue(int *);   
void dequeue(void);    
void display(int *);

// front & rear pointers
int front=-1, rear=-1;
int ele;
int n;

void enqueue(int *ptr)
{
    printf("Enter the element which you want to insert: ");
    scanf(" %d",&ele);
    if(rear==n-1)
        printf("Queue overflow\n");
    else {
        if(front==-1) 
            front=0;
        ptr[++rear]=ele;
    }
}

void dequeue(void)
{
    if(front==-1 || front>rear) {
        printf("Queue underflow\n");
    }
    else {
        printf("Deleted element:\n");
        front++;
    }
}

void display(int *ptr)
{
    if(front==-1 || front>rear) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf(" %d ",ptr[i]);
    printf("\n");
}

int main()
{
    printf("Enter the no of elements in queue: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the value of front and rear: ");
    scanf("%d %d",&front,&rear);

    if (rear >= n || front < -1 || front > rear+1) {
        printf("Invalid front/rear values!\n");
        return 1;
    }

    if(front != -1) {
        printf("Enter %d elements: ",rear-front+1);
        for(int i=front;i<=rear;i++)
            scanf(" %d",&a[i]);
    }

    display(a);
    enqueue(a);
    display(a);
    dequeue();
    display(a);
    return 0;
}