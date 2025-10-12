#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int x;
    struct student *next;
} std;
void create(std *);
void display(std *);
char ch;
std *head; 
void delete_anypos(void);

void create(std *ptr)
{   
    printf("Enter the data for the currnet node:\n");
    scanf(" %d", &ptr->x);
    ptr->next = NULL;
    printf("IF you want to continue enter 'y'- ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (std *)malloc(sizeof(std));
        ptr = ptr->next;
        create(ptr);
    }
    else
    {
        return;
    }
}

void display(std *ptr)
{
    printf("\nDisplay Linked list:\n");
    while (ptr != NULL)
    {
        printf("%d->", ptr->x);
        ptr = ptr->next;
    }
    printf("NULL");
}

void delete_anypos(void)
{
    int ele;
    std*loc;
    std *prevptr,*ptr;
    printf("\nEnter the data which you want to delete: ");
    scanf(" %d",&ele);
    ptr=head->next;
    prevptr=head;

    while(ptr!=NULL)
    {
        if(ptr->x==ele)
        {
            loc=ptr;
            prevptr->next=ptr->next;
            free(loc);
           printf("\n Element %d deleted successfully",ele);
           return;
        }
        prevptr=ptr;
        ptr=ptr->next;
    }
}

int main()
{
    head = (std *)malloc(sizeof(std));
    printf("Create a linked list:\n");
    create(head);
    display(head);
    delete_anypos();
    display(head);
    return 0;
}
