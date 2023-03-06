#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    Node* lchild;
    int data;
    Node *rchild;
};
typedef struct queue Queue;
struct queue
{
    Node ** data;
    int size;
    int capacity;
    int first_position;
};
void queue_init_default(Queue * q);
void queue_insert(Queue *q, Node* value);
Node* queue_extract(Queue *q);
void create(Node ** root);
int queue_empty(Queue q);
int main(int argc, char* argv[])
{
    Node *root=NULL;
    create(&root);
    return 0;
}
void create(Node ** root)
{
    Queue q;
    queue_init_default(&q);
    Node *p,*temp,*realroot;
    int x;
    realroot = (Node*)malloc(sizeof(Node));
    printf("Enter the value of the root: ");
    scanf("%d",&x);
    realroot->data=x;
    realroot->lchild=realroot->rchild=NULL;
    queue_insert(&q,realroot);
    while (!(queue_empty(q)))
    {
        p=queue_extract(&q);
        printf("Enter the value for left child of %d ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            temp=(Node*)malloc(sizeof(Node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->lchild=temp;
            queue_insert(&q,temp);
        }
        printf("Enter the value for right child of %d ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            temp=(Node*)malloc(sizeof(Node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->rchild=temp;
            queue_insert(&q,temp);
        }
    }
    (*root)=realroot;
    
}
int queue_empty(Queue q)
{
    if (q.size<= 0)
    {
        return 1;
    }
    return 0;
}
void queue_init_default(Queue * q)
{
    if (q != NULL)
    {
        q->capacity=10;
        q->size=0;
        q->first_position=0;
        q->data=(Node**)malloc(sizeof(Node*)*q->capacity);
    }
}
void queue_insert(Queue *q, Node* value)
{
    if (q->size >= q->capacity)
    {
        Node **temp;
        temp = (Node**)malloc(sizeof(Node*)*q->capacity*2);
        for(int i = 0; i<q->size; i++)
        {
            temp[i] = q->data[(q->first_position+i)%q->capacity];
        }
        free(q->data);
        q->data = temp;
        q->capacity *= 2;
        q->first_position=0;
    }
    q->data[(q->size+q->first_position)%q->capacity] = value;
    q->size++;
}
Node* queue_extract(Queue *q)
{
    Node *x=NULL;
    if (q->size <= 0)
    {
        return NULL;
    }
    x=q->data[q->first_position];
    q->first_position=(q->first_position+1)%q->capacity;
    q->size--;
    return x;
}