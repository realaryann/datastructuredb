#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    struct node *next;
};
void push(Node **top,int value);
int pop(Node **top);
void display(Node *top);
int main(int argc, char* argv[])
{
    Node *top;
    top=NULL;
    int ask;
    printf("*************** WELCOME TO STACK LL ADT ***************\n");
    printf("[1] for Push\n");
    printf("[2] for Pop\n");
    printf("[3] for Display\n");
    printf("[4] for Close program\n");
    printf("Enter Choice: ");
    scanf("%d",&ask);
    while(ask != 4)
    {
        if (ask == 1)
        {
            int val;
            printf("Enter value to push: ");
            scanf("%d",&val);
            push(&top,val);
        }
        else if(ask == 2)
        {
            pop(&top);
        }
        else if (ask == 3)
        {
            display(top);
        }
        printf("Enter Choice: ");
        scanf("%d",&ask);
    }
    return 0;
}
void display(Node *top)
{
    while (top != NULL)
    {
        printf("%d\n",top->data);
        top=top->next;
    }
}
int pop(Node **top)
{
    Node *p;
    int x=-1;
    if ((*top) == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        p=(*top);
        (*top)=(*top)->next;
        x=p->data;
        free(p);
        return x;
    }
}
void push(Node **top,int value)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        p->data = value;
        p->next = (*top);
        (*top)=p;
    }
}
