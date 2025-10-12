//queue using linked list with enque &deque
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}st;

st *head=NULL;

void push();
void pop();
void display();

void push(void)
{
   st *newnode = (st*) malloc(sizeof(st));   // ✅ fixed
   printf("Enter element to enqueue: ");
   scanf("%d", &newnode->x);

   newnode->next = NULL;

   if (head == NULL)
       head = newnode;
   else {
       st *temp = head;
       while (temp->next != NULL) {   
           temp = temp->next;
       }
       temp->next = newnode;     
   }

   printf("%d enqueued to queue\n", newnode->x);  
}

void pop(void){
    if(head==NULL){
        printf("Queue underflow\n");
        return;
    }
    st *ptr = head;               
    printf("Dequeued element: %d\n", ptr->x);
    head = head->next;
    free(ptr);
}

void display(){
    if(head==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    st *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    push();
    push();
    push();
    display();
    pop();
    display();
    return 0;
}
