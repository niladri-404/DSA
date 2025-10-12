#include<stdio.h>
#include<stdlib.h>

typedef struct std
{
    int x;
    struct std *next;
}std;

std * head,*loc;
char ch;

void create_cll(std *);
void display_cll(std *);
void deletionanypos_cll(std *);

void create_cll(std * ptr)
{
    printf("Enter the data for the current node:\n");
    scanf(" %d",&ptr->x);
    ptr->next=NULL;
    printf("If you want to continue enter 'y':\n");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y')
    {
        ptr->next=(std *)malloc(sizeof(std));
        ptr=ptr->next;
        create_cll(ptr);
    }
    else
        ptr->next = head;
}

void display_cll(std * ptr)
{
    do
    {
        printf(" %d->",ptr->x);
        ptr=ptr->next;
    } while (ptr != head);
    printf("(back to head)\n");
    
}

void deletionanypos_cll(std *ptr) 
{
    std *prevptr, *loc;
    int ele;
    printf("Enter the element to delete:\n");
    scanf("%d",&ele);

    prevptr = head;
    ptr = head->next;
    while(ptr != head) {
        if(ptr->x == ele) {
            loc = ptr;
            prevptr->next = ptr->next;
            free(loc);
            return;
        }
        prevptr = ptr;
        ptr = ptr->next;
    }
}


int main()
{
    printf("Create a node:\n");
    head = (std *)malloc(sizeof(std));

    printf("Create a circular linked list:\n");
    create_cll(head);

    printf("Display circular Linked list:\n");
    display_cll(head);

    deletionanypos_cll(head);

    printf("After deletion:\n");
    display_cll(head);
    
    return 0;
}
