#include <stdio.h>
#include <stdlib.h>
void num_to_string(int result, int len, char *new);
char int_to_char(int inte);
int str_to_num(char * str);
int convert_to_int(char element);
int main(int argc, char* argv[])
{
    int j;
    int result;
    char str1[]="11";
    char str2[]="12";
    result = str_to_num(str1)+str_to_num(str2);
    for (int i =result; i>0; i=i/10)
    {
        j++;
    }
    j++;
    char new[j];
    num_to_string(result,j,new);
    printf("%s",new);
}
char int_to_char(int inte)
{
    switch(inte)
    {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
    }
}
void num_to_string(int result, int len, char *new)
{
    int j;
    for(int i = result,j=len-2; i>0; i=i/10,j--)
    {
        new[j]=int_to_char(i%10);
    }
    new[len-1]='\0';
}
int convert_to_int(char element)
{
    switch(element)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
}
        
int str_to_num(char * str)
{
    int count;
    int multiplier=1;
    int running_sum = 0;
    for (count = 0; str[count] != '\0'; count++);
    for(int i = 0; i<count-1; i++)
    {
        multiplier=multiplier*10;
    }
    for( int j =0; j <count ; j++)
    {
        running_sum = running_sum+(multiplier*convert_to_int(str[j]));
        multiplier = multiplier/10;
    }
    return running_sum;
}