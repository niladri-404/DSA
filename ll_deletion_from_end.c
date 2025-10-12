#include<stdio.h>
#include<stdlib.h>

typedef struct std{
    int x;
    struct std *next;
}std;

std *head = NULL;
std*prevptr;
char ch;

void create(std *ptr) {
    printf("Enter the data for the current node:\n");
    scanf(" %d", &ptr->x);
    ptr->next = NULL;

    printf("If you want to continue enter 'Y':\n");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        ptr->next = (std*)malloc(sizeof(std));
        create(ptr->next);
    }
}

void display(std *ptr) {
    while (ptr != NULL) {
        printf(" %d ->", ptr->x);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

void delet_end(std*ptr)
{
    ptr=head;
    while(ptr->next!=NULL)
    {
        prevptr=ptr;
        ptr=ptr->next;
    }
    prevptr->next=NULL;
    free(ptr);
}

int main() {
    printf("Create a node:\n");
    head = (std*)malloc(sizeof(std));
    create(head);

    printf("Display the linked list:\n");
    display(head);

    printf("Deleting the first node...\n");
    delet_end(head);

    printf("After deletion:\n");
    display(head);
    return 0;
}
