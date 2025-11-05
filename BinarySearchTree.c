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

/* void PreOrder(struct node*root)
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
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
    else
    return;
}
    */
void InOrder(struct node*root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
    else
    return;
}

int isBST(struct node*root)
{
    static struct node*prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL && root->data<=prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
    return 1;
}

int main()
{
    // constructing the root node
    struct node *p = createNode(50);
    struct node *p1 = createNode(30);
    struct node *p2 = createNode(70);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(40);
    struct node *p5 = createNode(60);
    struct node *p6 = createNode(80);
    
    //       50
    //      /  \
    //    30    70
    //   / \    / \
    //   20  40  60  80

    
    // Linking the node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

//    printf("Preorder traversal:\n ");
//    PreOrder(p);

//   printf("\nPostorder traversal:\n ");
//    PostOrder(p);

    printf("Inorder traversal:\n ");
    InOrder(p);
    
    if(isBST(p))
    {
        printf("\nThis is a BST.");
    }

    return 0;

}
