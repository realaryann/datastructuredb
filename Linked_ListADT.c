#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    struct node*next;
};
void create(Node **first);
void display(Node *point);
void delete(Node **first,int index);
void insert(Node **first, int value, int index);
int count(Node *first);
int main(int argc, char* argv[])
{
    int ask;
    Node *first;
    first = (Node*)malloc(sizeof(Node));
    printf("\n\n*********** Welcome to Linked List ADT ***********\n");
    printf("[1] for Create LL\n");
    printf("[2] for Insert Element\n");
    printf("[3] for Delete Element\n");
    printf("[4] for Display LL\n");
    printf("[5] for Count all nodes\n");
    printf("[6] for Exit program\n");
    printf("Enter Choice: ");
    scanf("%d",&ask);
    while (ask != 6)
    {
        if(ask == 1)
        {
            create(&first);
        }
        else if (ask == 2)
        {
            int val,index;
            printf("Enter value to insert: ");
            scanf("%d",&val);
            printf("Enter index to insert: ");
            scanf("%d",&index);
            insert(&first,val,index);
        }
        else if (ask == 3)
        {
            int index;
            printf("Enter index to delete: ");
            scanf("%d",&index);
            delete(&first,index);
        }
        else if (ask == 4)
        {
            display(first);
        }
        else if (ask == 5)
        {
            printf("The number of nodes are: %d\n",count(first));
        }
        printf("Enter Choice: ");
        scanf("%d",&ask);
    }
    return 0;
}
int count(Node *first)
{
    printf("\n");
    int count = 0;
    while (first != NULL)
    {
        count++;
        first=first->next;
    }
    return count;
}
void insert(Node **first, int value, int index)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if (index == 0)
    {
        p->data = value;
        p->next=(*first);
        (*first)=p;
    }
    /*
        [1] [2] [3] [4] [5]
        0   1   2   3    4
        if(index == 2)
        bring p to index-1
        q->data = value;
        q->next = p->next;
        p->next = q;

    */
    else
    {
        p=(*first);
        Node *q;
        q=(Node*)malloc(sizeof(Node));
        for(int i =0; i<index-1; i++)
        {
            p=p->next;
        }
        q->data = value;
        q->next = p->next;
        p->next = q;
    }
}
void delete(Node **first,int index)
{
    Node *p,*q;
    if (index == 0)
    {
        p=(*first);
        (*first)=(*first)->next;
        free(p);
    }
    else
    {
        p=(*first);
        /*
        [1] [2] [3] [4]
        0   1   2   3
        if index == 2
        p will move 2 times from first to get to element to delete
        */
        for(int i = 0; i<index; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        free(p);
    }
}

void display(Node *point)
{
    printf("\n");
    while (point != NULL)
    {
        printf("%d->",point->data);
        point=point->next;
    }
    printf("[End of LL]\n\n");
}
void create(Node **first)
{
    Node *p,*end;
    int len,val;
    printf("Enter initial length of LL: ");
    scanf("%d",&len);
    printf("Enter first element: ");
    scanf("%d",&val);
    (*first)->data = val;
    (*first)->next = NULL;
    end = (*first);
    for(int i = 1; i<len; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        printf("Enter element: ");
        scanf("%d",&p->data);
        p->next = NULL;
        end->next = p;
        end=p;
    }
}