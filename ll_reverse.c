#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int x;
    struct student *next;
} std;
void create(std *);
void display(std *);
std *  reverse_ll(std *);
char ch;
std *head, *ptr1;

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

std * reverse_ll(std *ptr)
{
    std *previous, *counter, *current1;
    {
        current1 = ptr;
        previous = NULL;
        while (current1 != NULL)
        {
            counter = current1->next;
            current1->next = previous;
            previous = current1;
            current1 = counter;
        }
        ptr = previous;
        return (ptr);
    }
}

int main()
{
    head = (std *)malloc(sizeof(std));
    printf("Create a linked list:\n");
    create(head);
    display(head);
    std * rev = reverse_ll(head);
    printf("After reversal:\n");
    display(rev);
    return 0;
}
