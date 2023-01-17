#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    struct node *next;
};
void display(Node *first);
void reverse(Node **first);
void create(Node **first, int array[], int len);
int main(int argc, char* argv[])
{
    Node *first;
    first =(Node*)malloc(sizeof(Node));
    int array[]={1,2,3,4,5,6};
    int len = sizeof(array)/sizeof(int);
    create(&first,array,len);
    reverse(&first);
    display(first);
    return 0;
}
void display(Node *first)
{
    while (first != NULL)
    {
        printf("%d->",first->data);
        first=first->next;
    }
}
void reverse(Node **first)
{
    Node *p,*q,*r;
    p=(*first);
    while (p != NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    (*first)=q;
}
void create(Node **first, int array[], int len)
{
    Node *p,*end;
    (*first)->data=array[0];
    (*first)->next=NULL;
    end=(*first);
    for(int i = 1; i<len; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        p->data=array[i];
        p->next=NULL;
        end->next=p;
        end=p;
    }
}