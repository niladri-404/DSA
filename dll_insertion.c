//insertion at double linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int x;
    struct list *nextptr;
    struct list *prevptr;
}dl;

dl *head;

void create_dl(dl *);
void display_dl(dl *);
void insert_beg_dll();
void insert_end_dll();
void insert_anypos_dll(dl *);

void create_dl(dl *ptr)
{
    char ch;
    printf("Enter the data: ");
    scanf("%d",&ptr->x);
    ptr->nextptr=NULL;
    printf("Do you want to continue (y/n): ");
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y')
    {
        ptr->nextptr=(dl*)malloc(sizeof(dl));
        ptr->nextptr->prevptr=ptr;
        ptr=ptr->nextptr;
        create_dl(ptr);
    }
}

void display_dl(dl *ptr)
{
    printf("\nDisplay the double linked list (forward): ");
    while(ptr != NULL)
    {
        printf("%d->", ptr->x);
        if(ptr->nextptr == NULL)
            break;
        ptr = ptr->nextptr;
    }
    printf("NULL");

    printf("\nDisplay the double linked list (backward): ");
    while(ptr != NULL)
    {
        printf("%d->", ptr->x);
        ptr = ptr->prevptr;
    }
    printf("NULL\n");
}

void insert_beg_dll(void)
{
    dl *newnode = (dl*) malloc(sizeof(dl));
    printf("\nEnter the data to insert at beginning: ");
    scanf("%d", &newnode->x);     
    newnode->prevptr = NULL;    
    newnode->nextptr = head;      
    if (head != NULL)           
        head->prevptr = newnode;
    head = newnode;               
}

void insert_end_dll()
{
    dl *newnode = (dl*)malloc(sizeof(dl));
    printf("\nEnter the data to insert at end: ");
    scanf("%d", &newnode->x);
    newnode->nextptr = NULL;

    dl *ptr = head;
    while (ptr->nextptr != NULL)
        ptr = ptr->nextptr;
        
    newnode->prevptr = ptr;
    ptr->nextptr = newnode;

    printf("\n%d element is inserted at the end", newnode->x);
}

void insert_anypos_dll(dl *ptr)
{
    dl *newnode = (dl*)malloc(sizeof(dl));
    int ele;
    printf("\nEnter the element after which to insert: ");
    scanf("%d",&ele);
    printf("Enter the data to insert: ");
    scanf("%d",&newnode->x);
    
    while(ptr!=NULL)
    {
        if(ptr->x == ele)
        {  
            newnode->prevptr=ptr;
            newnode->nextptr=ptr->nextptr;
            if(ptr->nextptr != NULL)  
                ptr->nextptr->prevptr=newnode;
            ptr->nextptr=newnode;
            break;
        }
        ptr = ptr->nextptr;
    }
}

int main()
{
    head=(dl*)malloc(sizeof(dl));
    head->prevptr=NULL;
    create_dl(head);
    display_dl(head);
    insert_beg_dll();
    display_dl(head);
    insert_end_dll();
    display_dl(head);
    insert_anypos_dll(head);
    display_dl(head);
    return 0;
}