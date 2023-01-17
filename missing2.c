#include <stdio.h>

void missing(int array[], int len);
void swap(int *i, int*j);
void sort(int array[], int len);
void check(int array[], int len);
int main(int argc, char* argv[])
{
    int array[]={6,5,4,3,2,1};
    int len = sizeof(array)/sizeof(int);
    check(array,len);
    return 0;
}
void swap(int *i, int*j)
{
    int temp = *i;
    *i=*j;
    *j=temp;
}
void sort(int array[], int len)
{
    int i,j;
    for (i=0; i<len-1; i++)
    {
        for(j=0; j<len-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);
            }
        }
    }
    missing(array,len);
}
void check(int array[], int len)
{
    int i=0;
    int check = 0;
    for(i=0; i<len; i++)
    {
        if (array[i]>array[i+1])
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        missing(array,len);
    }
    else
    {
        sort(array,len);
    }

}
void missing(int array[], int len)
{
    int i=0;
    int diff = array[0]-i;
    for(i=0; i<len; i++)
    {
        if (array[i]-i != diff)
        {
            while(diff < array[i]-i)
            {
                printf("%d is missing\n",i+diff);
                diff++;
            }
        }
    }
}