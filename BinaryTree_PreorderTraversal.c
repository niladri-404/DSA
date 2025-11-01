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

struct node *createTree()
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    struct node *root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = createTree();
    printf("Enter right child of %d:\n", data);
    root->right = createTree();
    return root;
}

void PreOrder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
    else
    return;
}

void PostOrder(struct node*root)
{
    if(root!=NULL)
    {
        PreOrder(root->left);
        PreOrder(root->right);
        printf("%d ",root->data);
    }
    else
    return;
}

void InOrder(struct node*root)
{
    if(root!=NULL)
    {
        PreOrder(root->left);
        printf("%d ",root->data);
        PreOrder(root->right);
    }
    else
    return;
}

int main()
{
    // constructing the root node
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    
    // Linking the node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left=p3;
    p1->right=p4;

    printf("Preorder traversal:\n ");
    PreOrder(p);

    printf("\nPostorder traversal:\n ");
    PostOrder(p);

    printf("\nInorder traversal:\n ");
    InOrder(p);

    return 0;
}