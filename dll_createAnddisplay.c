#include<stdio.h>
#include<stdlib.h>

typedef struct std
{
    int x;
    struct std * nextptr;
    struct std * prevptr;
}dl;
char ch;
void create_dll(dl*);
void display_dll(dl*);

void create_dll(dl * ptr)
{
    printf("Enter element:\n");
    scanf(" %d",&ptr->x);
    ptr->nextptr=NULL;
    printf("If you want to continue enter 'y':\n");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y')
    {
        ptr->nextptr=(dl*)malloc(sizeof(dl));
        ptr->nextptr->prevptr=ptr;
        ptr=ptr->nextptr;
        create_dll(ptr);
    }
}

void display_dll(dl *ptr)
{
    dl *last = NULL;

    printf("Forward:\n");
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->x);
        last = ptr;            // store last node
        ptr = ptr->nextptr;
    }
    printf("NULL\n");

    printf("Backward:\n");
    while(last != NULL)
    {
        printf("%d -> ", last->x);
        last = last->prevptr;
    }
    printf("NULL\n");
}


int main()
{
    printf("Create a node:\n");
    dl *head = (dl *)malloc(sizeof(dl));
    printf("Create a dauble linked list:\n");
    create_dll(head);
    printf("Display dauble Linked list:\n");
    display_dll(head);
    return 0;
}
