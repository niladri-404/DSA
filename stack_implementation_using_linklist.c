//stack using linked list including pop & push
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}st;

st *head = NULL;

void push();
void pop();
void display();

void push(void)
{
    st *newnode = (st*) malloc(sizeof(st));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter element to push: ");
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

    printf("%d pushed to stack\n", newnode->x);  
}

void pop(void){
    if(head == NULL){
        printf("Stack underflow\n");
        return;
    }
    if(head->next == NULL){
        printf("Popped element: %d\n", head->x);
        free(head);
        head = NULL;
        return;
    }
    st *ptr = head;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    printf("Popped element: %d\n", ptr->next->x);
    free(ptr->next);
    ptr->next = NULL;
}

void display(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (from bottom to top): ");
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