#include <stdio.h>
#include <stdlib.h>
//This Queue implementation can be used to create binary trees.

typedef struct queue Queue;
struct queue
{
    int *data;
    int size;
    int capacity;
    int first_position;
};
enum status {FAILURE, SUCCESS};
typedef enum status Status;
Status queue_init_default(Queue *q);
int queue_remove(Queue *q);
Status queue_insert(Queue* q,int value);
int queue_front(Queue * q, Status* status);
int main(int argc, char* argv[])
{
    return 0;
}
Status queue_init_default(Queue* q)
{
    if (q  != NULL)
    {
        q->first_position = 0;
        q->size=0;
        q->capacity=10;
        q->data = (int*)malloc(sizeof(int)*q->capacity);
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}

Status queue_insert(Queue* q,int value)
{
    if (q->size >= q->capacity)
    {
        int* temp;
        temp = (int*)malloc(sizeof(int)*q->capacity*2);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for(int i = 0; i<q->size; i++)
        {
            temp[i] = q->data[(q->first_position+i)%q->capacity];
        }
        free(q->data);
        q->data=temp;
        q->capacity*=2;
        q->first_position = 0;
    }
    q->data[(q->first_position + q->size)%q->capacity] = value;
    q->size++;
    return SUCCESS;
}
int queue_remove(Queue *q)
{
    int x=-1;
    if (q != NULL)
    {
        x=q->data[q->first_position];
        q->first_position=(q->first_position+1)%q->capacity;
        q->size--;
    }
    return x;
}
int queue_front(Queue * q, Status* status)
{
    if (q->size <= 0)
    {
        if (status != NULL)
        {
            *status = FAILURE;
        }
        return -8008;
    }
    if (status != NULL)
    {
        *status = SUCCESS;
    }
    return q->data[q->first_position];
}
