#include <stdio.h>
#include <stdlib.h>

struct array
{
    int array[10];
    int size;
    int length;
};
typedef struct array Array;
void display(Array arr);
void append(Array *parr,int x);
void insert(Array *parr, int index, int value);
void delete(Array *parr, int index);

int main(int argc, char* argv[])
{
    Array array;
    array.size=10;
    int ind,val,x,i;
    printf("Enter the total number of elements of the array: ");
    scanf("%d",&array.length);
    for (i=0; i<array.length; i++)
    {
        printf("Enter element: ");
        scanf("%d",&array.array[i]);
    }
    printf("Enter number to append: ");
    scanf("%d",&x);
    append(&array,x);
    printf("Enter index to insert: ");
    scanf("%d",&ind);
    printf("Enter value to insert: ");
    scanf("%d",&val);
    insert(&array,ind,val);
    delete(&array, 0);
    display(array);
    return 0;
    
}
void append(Array *parr, int x)
{
    if (parr->length < parr->size)
    {
        parr->array[parr->length]=x;
    }
    parr->length++;
}
void display(Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ",arr.array[i]);
    }
}

void insert(Array *parr, int index, int value)
{
    int i;
    for (i=parr->length; i>index; i--)
    {
        parr->array[i]=parr->array[i-1];
    }
    parr->array[index]=value;
    parr->length++;
}

void delete(Array *parr, int index)
{
    int i;
    for(i=index; i<(parr->length-1); i++)
    {
        parr->array[i] = parr->array[i+1];
    }
    parr->length--;
}
