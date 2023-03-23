#include <stdio.h>
#include <stdlib.h>
void heap_insert(int heap[], int *len,int value);
void fix_up(int heap[], int index);
void iterative_fix_up(int heap[], int index);
void fix_down(int heap[], int index, int len);
void heap_remove(int heap[],int *len);
void iterative_fix_down(int heap[], int index, int len);

int main(int argc, char* argv[])
{
    int heap[50];
    int len=0;
    for(int i =0; i<11; i++)
    {
        heap_insert(heap,&len,i);
    }
    heap_remove(heap,&len);
    for(int i = 0 ; i<len; i++)
    {
        printf("%d\n",heap[i]);
    }
    return 0;
}

void heap_remove(int heap[],int *len)
{
    int temp;
    temp=heap[0];
    heap[0]=heap[*len-1];
    heap[*len]=temp;
    (*len)--;
    iterative_fix_down(heap,0,*len);
}

void iterative_fix_down(int heap[], int index, int len)
{
    int index_left;
    int index_right;
    int largest;
    int temp;
    do
    {
        index_left=2*index+1;
        index_right=2*index+2;
        if (heap[index_left] > heap[index_right])
            largest=index_left;
        else
            largest=index_right;
        temp = heap[index];
        heap[index]=heap[largest];
        heap[largest]=temp;
        index=largest;
    }while((index_left < len) && (index_right <len));
}

void fix_down(int heap[], int index, int len)
{
    int index_right=2*index+2;
    int index_left=2*index+1;
    int largest;
    if (index_left<len)
    {
        if (index_right<len)
        {
            if (heap[index_left] > heap[index_right])
            largest=index_left;
            else
            largest=index_right;
            int temp;
            temp=heap[index];
            heap[index]=heap[largest];
            heap[largest]=temp;
            fix_down(heap,largest,len);
        }
    }
}

void heap_insert(int heap[], int *len,int value)
{
    heap[*len]=value;
    iterative_fix_up(heap,*len);
    (*len)++;
}

void iterative_fix_up(int heap[], int index)
{
    int parent_index;
    while (index > 0)
    {
        parent_index = (index-1)/2;
        if (heap[index]>heap[parent_index])
        {
            int temp;
            temp=heap[index];
            heap[index]=heap[parent_index];
            heap[parent_index]=temp;
            index=parent_index;
        }
        else{
            break;
        }
        
    }
}
void fix_up(int heap[], int index)
{
    int parent_index;
    if (index >0)
    {
        int temp;
        parent_index=(index-1)/2;
        if (heap[parent_index] < heap[index])
        {
            temp =heap[index];
            heap[index]=heap[parent_index];
            heap[parent_index]=temp;
            fix_up(heap,parent_index);

        }
    }
}



