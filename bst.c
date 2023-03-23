#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    Node* lchild;
    int data;
    Node* rchild;
};
void bst_insert(Node **root, int value);
Node* bst_search(Node* root, int value);
void inorder(Node *temp);
int main(int argc, char* argv[])
{
    Node* root=NULL;
    for(int i = 0; i<10; i++)
    {
        bst_insert(&root,i);
    }
    inorder(root);
    return 0;
}
Node* bst_search(Node* root, int value)
{
    while(root)
    {
        if (root->data == value)
        {
            return root;
        }
        else if (root->data > value)
        {
            root=root->lchild;
        }
        else{
            root=root->rchild;
        }
    }
    return NULL;
}
void inorder(Node *temp)
{
    if (temp)
    {
        inorder(temp->lchild);
        printf("%d ",temp->data);
        inorder(temp->rchild);
    }
}
void bst_insert(Node **root, int value)
{
    Node *temp,*mover=*root,*prev;
    if (*root == NULL)
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->data=value;
        temp->lchild=temp->rchild=NULL;
        *root = temp;
        return;
    }
    while (mover)
    {
        prev=mover;
        if (mover->data > value)
        {
            mover=mover->lchild;
        }
        else if (mover->data < value)
        {
            mover=mover->rchild;
        }
    }
    temp = (Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->lchild=temp->rchild=NULL;
    if (prev->data > value) prev->lchild=temp;
    else prev->rchild=temp;
}