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

int main(int argc, char* argv[])
{
    Array array;
    array.size=10;
    int x;
    int i;
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
    display(array);
    return 0;
    
}
void append(Array *parr, int x)
{
    if (parr->length < parr->size)
    {
        parr->array[parr->length]=x;
    }
    parr->length=parr->length+1;
}
void display(Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ",arr.array[i]);
    }
}
