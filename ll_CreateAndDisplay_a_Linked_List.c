#include <stdio.h>
#include <stdlib.h>

typedef struct std
{
    int x;
    struct std *next;
} std;
void create(std *);
void display(std *);
char ch;

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
    while (ptr != NULL)
    {
        printf(" %d->", ptr->x);
        ptr = ptr->next;
    }
}

int main()
{
    printf("Create a node:\n");
    std *head = (std *)malloc(sizeof(std));
    printf("Create a linked list:\n");
    create(head);
    printf("Display Linked list:\n");
    display(head);
    return 0;
}