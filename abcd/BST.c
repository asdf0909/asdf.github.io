#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
}BSTnode;

BSTnode* insert(BSTnode* T,int x)
{
    BSTnode* temp;

    if(T == NULL)
    {
       //create a node
       temp = (BSTnode*)malloc(sizeof(BSTnode));
       temp->data = x;
       temp->left = NULL;
       temp->right = NULL;
       return temp;
    }
    else if(x<T->data)
        T->left = insert(T->left,x);
    else if(x>=T->data)
        T->right = insert(T->right,x);

    return T;
}

void print(BSTnode* T)
{
    if(T!=NULL)
    {
        printf("%d ",T->data);
        print(T->left);
        print(T->right);
    }
}


int main()
{
    BSTnode *root=NULL;
    int n,i,x;


    printf("\nEnter how many nodes:");
    scanf("%d",&n); // n=5
    for(i=1;i<=n;i++)
        {
            printf("\nEnter node value:");
            scanf("%d",&x);
            root = insert(root,x);
        }
    print(root);

    return 0;
}