// deletion at double linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int x;
    struct list *nextptr;
    struct list *prevptr;
} dl;

dl *head;

void create_dl(dl *);
void display_dl(dl *);
void delete_beg_dll();
void delete_end_dll();
void delete_anypos_dll(dl *);

void create_dl(dl *ptr)
{
    char ch;
    printf("Enter the data: ");
    scanf("%d", &ptr->x);
    ptr->nextptr = NULL;
    printf("Do you want to continue: ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->nextptr = (dl *)malloc(sizeof(dl));
        ptr->nextptr->prevptr = ptr;
        ptr = ptr->nextptr;
        create_dl(ptr);
    }
}

void display_dl(dl *ptr)
{
    printf("Display the double linked list (forward): ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->x);
        if (ptr->nextptr == NULL)
            break;
        ptr = ptr->nextptr;
    }
    printf("NULL");

    printf("\nDisplay the double linked list (backward): ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->x);
        ptr = ptr->prevptr;
    }
    printf("NULL");
}

void delete_beg_dll(void)
{
    printf("\nFirst element is deleted:\n");
    head->nextptr->prevptr = head->prevptr;
    dl *loc = head;
    head = head->nextptr;
    head->prevptr = loc->prevptr;
    free(loc);
}

void delete_end_dll(void)
{
    printf("\nLast element is deleted\n");
    dl *ptr = head;
    while (ptr->nextptr != NULL)
        ptr = ptr->nextptr;
    ptr->prevptr->nextptr = ptr->nextptr;
    dl *loc = ptr;
    free(loc);
}

void delete_anypos_dll(dl *ptr)
{
    int ele;
    printf("\nEnter the element you want to delete:");
    scanf("%d", &ele);

    while (ptr != NULL)
    {
        if (ptr->x == ele)
        {
            ptr->prevptr->nextptr = ptr->nextptr;
            ptr->nextptr->prevptr = ptr->prevptr;
            dl *loc = ptr;
            free(loc);
            break;
        }

        else
            ptr = ptr->nextptr;
    }
}

int main()
{
    head = (dl *)malloc(sizeof(dl));
    head->prevptr = NULL;
    create_dl(head);
    display_dl(head);
    delete_beg_dll();
    display_dl(head);
    delete_end_dll();
    display_dl(head);
    delete_anypos_dll(head);
    display_dl(head);
    return 0;
}