#include<stdio.h>
#include<stdlib.h>

typedef struct std{
    int x;
    struct std *next;
}std;
std *head;

void create(std*);
void display(std*);
void search_ll(std *);
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

void search_ll(std *ptr)
{
    int ele;
    printf("\nEnter the element you want to find:\n");
    scanf("%d",&ele);
    while(ptr != NULL)
    {
        if(ptr->x==ele)
        {
            printf("Element %d found\n",ele);
            return;
        }
        
        else
            ptr=ptr->next;
    }
}
    

int main(){
    printf("Create a node:\n");
    head=(std*)malloc(sizeof(std));
     printf("Created linked list is:\n");
    create(head);
    printf("Display the linked list:\n");
    display(head);
    search_ll(head);
    return 0;
}