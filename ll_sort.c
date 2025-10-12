#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int x;
    struct student *next;
} std;
void create(std *);
void display(std *);
void sort_ll(std *);
void swap_ll(std *,std *);
char ch;
std *head; 

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
    printf("NULL\n");
}

void swap_ll(std *x1, std *x2)
{
    int temp=x1->x;
    x1->x=x2->x;
    x2->x=temp;
}
void sort_ll(std *ptr)
{
    std *ptr1;
    while (ptr != NULL)
    {
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr->x > ptr1->x)
                swap_ll(ptr, ptr1);
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

int main()
{
    head = (std *)malloc(sizeof(std));
    printf("Create a linked list:\n");
    create(head);
    display(head);
    sort_ll(head);
    printf("After sorting:");
    display(head);
    return 0;
}
