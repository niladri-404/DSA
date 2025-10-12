#include<stdio.h>
#include<stdlib.h>

typedef struct std{
    int x;
    struct std *next;
}std;
std *head;

void create(std*);
void display(std*);
char ch;

void create(std *ptr){
    printf("Enter the data for the current node:\n");
    scanf(" %d",&ptr->x);
    ptr->next=NULL;
    printf("If you want to continue enter 'Y':\n");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y'){
        ptr->next=(std*)malloc(sizeof(std));
        ptr=ptr->next;
        create(ptr);
    }
    else{
        return;
    }
}
void display(std *ptr){
    while(ptr !=NULL){
        printf(" %d ->",ptr->x);
        ptr=ptr->next;
    }
}

void insert_end(std *ptr){
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    std *new = (std*)malloc(sizeof(std));
    printf("Enter the data to insert at the end:\n");
    scanf("%d", &new->x);
    new->next = NULL;
    ptr->next = new;
}   

int main(){
    printf("Create a node:\n");
    head=(std*)malloc(sizeof(std));
     printf("Created linked list is:\n");
    create(head);
    printf("Display the linked list:\n");
    display(head);
    printf("\nEnter the elements you want to insert:\n");
    insert_end(head);
    printf("After insertion:\n");
    display(head);
    return 0;
}