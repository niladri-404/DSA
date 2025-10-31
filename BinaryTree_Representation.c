#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    // constructing the root node
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
    
    // Linking the node with left and right children
    p->left = p1;
    p->right = p2;

    // Print the data
    printf("Root node: %d\n", p->data);
    printf("Left child: %d\n", p->left->data);
    printf("Right child: %d\n", p->right->data);
    return 0;
}