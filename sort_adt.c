#include <stdio.h>
#include <stdlib.h>

void bubblesort(int array[],int len);
void display(int array[],int len);
void swap(int* i, int *j);
void selectionsort(int array[], int len);
void insertionsort(int array[],int len);
int main(int argc, char* argv[])
{
    int array[]={6,5,4,3,2,1};
    int len = sizeof(array)/sizeof(int);
    selectionsort(array,len);
    display(array,len);
    return 0;
}
void selectionsort(int array[], int len)
{
    int i,j,k;
    for(i=0; i<len-1; i++)
    {
        for(j=i,k=i; j<len; j++)
        {
            if (array[j]<array[k])
            {
                k=j;
            }
        }
        swap(&array[i],&array[k]);
    }
}
/*
    [2 1  3 4 5 6]
    0 1 2 3 4 5
    i=1
    x=2
    j=0
    array[j]>x = 2>1
    array[j+1] = array[j]= 

*/
void insertionsort(int array[],int len)
{
    int i,j,x;
    for(i=1; i<len; i++)
    {
        j=i-1;
        x=array[i];
        while(j > -1 && array[j] > x)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=x;
    }
}
void display(int array[],int len)
{
    printf("\n");
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
void bubblesort(int array[],int len)
{
    int i,j;
    for(i=0; i<len-1; i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);
            }
        }
    }
}
void swap(int *i, int*j)
{
    int temp;
    temp =*i;
    *i=*j;
    *j=temp;
}