#include <stdio.h>
#include <stdlib.h>

struct vector
{
    int *data;
    int size;
    int capacity;
};

typedef struct vector Vector;
void show_instructions(void);
void vector_destroy(Vector *vector);
void display_vector(Vector vector);
void insert_at_position(Vector *vector,int index, int value);
int vector_return_capacity(Vector vector);
int vector_return_size(Vector vector);
Vector vector_init_default(Vector vector);
void vector_push_back(Vector *vector,int value);
int main(int argc, char* argv[])
{
    int ask;
    Vector vector;
    printf("Welcome to Vector ADT\n");
    show_instructions();
    printf("Enter choice: ");
    scanf("%d",&ask);
    while (ask != 9)
    {
        if (ask == 1)
        {
            vector=vector_init_default(vector);
        }
        else if (ask == 2)
        {
            int value;
            printf("Enter element to push back: ");
            scanf("%d",&value);
            vector_push_back(&vector,value);
        }
        else if (ask == 3)
        {
            display_vector(vector);
            printf("\n");
        }
        else if (ask == 4)
        {
            int value,index;
            printf("Enter value to insert: ");
            scanf("%d",&index);
            insert_at_position(&vector,index,value);
        }
        else if (ask == 5)
        {
            printf("\nThe capacity of vector is :%d\n",vector_return_capacity(vector));
        }
        else if (ask == 6)
        {
            printf("The size of vector is: %d\n",vector_return_size(vector));
        }
        else if (ask == 7)
        {
            vector_destroy(&vector);
        }
        else if (ask == 8)
        {
            show_instructions();
        }
        printf("Enter choice: ");
        scanf("%d",&ask);
    }
    return 0;
}
void show_instructions(void)
{
    printf("[1] to initialize vector\n");
    printf("[2] to push back element\n");
    printf("[3] to display vector\n");
    printf("[4] to insert at position\n");
    printf("[5] to return capacity\n");
    printf("[6] to return size\n");
    printf("[7] to destroy vector\n");
    printf("[8] to show instructions\n");
    printf("[9] to exit adt\n");
}
void vector_destroy(Vector *vector)
{
    if (vector != NULL)
    {
        free(vector->data);
    }
    else
    {
        printf("ERROR: Vector not initialized\n");
        exit(1);
    }
}
void display_vector(Vector vector)
{
    for (int i = 0; i<vector.size; i++)
    {
        printf("%d->",vector.data[i]);
    }
}
void insert_at_position(Vector *vector,int index, int value)
{
    if (index > vector->size || index < 0)
    {
        printf("ERROR: Cannot insert at that position\n");
        exit(1);
    }
    else{
        for(int i = vector->size; i>index; i--)
        {
            vector->data[i]=vector->data[i-1];
        }
        vector->data[index]=value;
        vector->size++;
    }
}
int vector_return_capacity(Vector vector)
{
    return vector.capacity;
}
int vector_return_size(Vector vector)
{
    return vector.size;
}
void vector_push_back(Vector *vector,int value)
{
    if (vector->size>=vector->capacity)
    {
        int *temp;
        temp=(int*)malloc(sizeof(int)*vector->capacity*2);
        if (temp == NULL)
        {
            printf("ERROR: Unable to extend vector\n");
            exit(1);
        }
        for(int i = 0; i<vector->size; i++)
        {
            temp[i]=vector->data[i];
        }
        free(vector->data);
        vector->data=temp;
        vector->capacity = vector->capacity*2;
    }
    vector->data[vector->size]=value;
    vector->size++;
}
Vector vector_init_default(Vector vector)
{
    vector.capacity=1;
    vector.size=0;
    vector.data=(int*)malloc(sizeof(int)*vector.capacity);
    if (vector.data == NULL)
    {
        printf("ERROR: Program was not able to allocate memory for data\n");
        exit(1);
    }
    return vector;
}
