#include<stdio.h>
#include<stdlib.h>

typedef struct std
{
    int x;
    struct std *next;
}std;
std * head;
void create_cll(std *);
void display_cll(std *);
void insertmid_cll(std *);
char ch;

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
        ptr->next = head;;
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

void insertmid_cll(std *ptr) {
    int ele;
    std *new = (std *)malloc(sizeof(std));
    printf("Enter data to insert in the middle: ");
    scanf("%d", &new->x);

    printf("Enter the element after which you want to insert:");
    scanf("%d", &ele);

    while (ptr->next != head) {
        if (ptr->x == ele) {
            new->next = ptr->next;
            ptr->next = new;
            return;
        }
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
    insertmid_cll(head);
    printf("After insertion:\n");
    display_cll(head);
    return 0;
}

