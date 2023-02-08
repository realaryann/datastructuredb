#include <stdio.h>
#include <stdlib.h>
void possible_substrings(char str[]);

int main(int argc, char* argv[])
{
    char str[]="sac";
    possible_substrings(str);
    return 0;
}
void possible_substrings(char str[])
{
    int len,i,j,z;
    for(len=0; str[len] != '\0'; len++);
    for(i=0; i<len; i++)
    {
        z=i+1;
        for(j=i; z<=len; j++,z++)
        {
            for(j=i; j<z; j++)
            {
                printf("%c",str[j]);
            }
            printf("\n");
        }
    }
}   