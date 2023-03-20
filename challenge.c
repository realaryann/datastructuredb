#include <stdio.h>
#include <stdlib.h>
/*
strategy
1)First get all the possible substrings of the string
2)Send all substrings to the is palin function to check for palind
3) if it is a palin, add it to the result array
4) iterate through the result array in a o(n^2) algorithm to check if any strings are same
5) if they are same, decrease count, otherwise count
*/
void get_substrings(char *teststring, char** totalsubstrings, int len);
int ispalin(char *tempcase);
int unique_counter(char **totalsubstrings);
int string_check(char *a, char*b);
int main(int argc, char* argv[])
{
    char teststring[100];
    scanf("%s",&teststring);
    int len=0;
    for(len; teststring[len] != '\0'; len++);
    char* totalsubstrings[100];
    for(int i =0; i<10; i++)
    {
        totalsubstrings[i]=NULL;
    }
    get_substrings(teststring,totalsubstrings,len);
    printf("%d unique palindrome substrings exist" ,unique_counter(totalsubstrings));
}
int string_check(char *a, char*b)
{
    int len1,len2;
    for(len1 = 0; a[len1] != '\0'; len1++);
    for(len2 = 0; b[len2] != '\0'; len2++);
    if (len1 != len2)
    {
        return 0;
    }
    else{
        for(int i =0; i<len1; i++)
        {
            if (a[i] != b[i])
            {
                return 0;
            }
        }
        return 1;
    }
}
int unique_counter(char ** totalsubstrings)
{
    int newlen,count=0;
    for(newlen =0; totalsubstrings[newlen] != NULL; newlen++);
    for(int i = 0; i<newlen; i++)
    {
        for(int j =i+1; j<newlen; j++)
        {
            if (string_check(totalsubstrings[i],totalsubstrings[j]))
            {
                count--;
                break;
            }
        }
        count++;
    }
    return count;
}
void get_substrings(char *teststring, char** totalsubstrings, int len)
{
    char *tempcase;
    int i,j,k,index,subindex=0;
    for(i =0; i<len; i++)
    {
        for(j=i; j<len; j++)
        {
            tempcase = (char*)malloc(sizeof(char)*(len+1));
            for(k=i,index=0; k<=j; k++,index++)
            {
                tempcase[index]=teststring[k];
            }
            tempcase[index]='\0';
            if (ispalin(tempcase))
            {
                totalsubstrings[subindex]=tempcase;
                subindex++;
            }
        }
    }
}
int ispalin(char *tempcase)
{
    int len,i,j;
    for(len =0; tempcase[len] != '\0'; len++);
    if(len == 1)
    {
        return 1;
    }
    else{
        for(i=0, j=len-1; i<j; i++,j--)
        {
            if (tempcase[i] != tempcase[j])
            {
                return 0;
            }
        }
        return 1;
    }
}
