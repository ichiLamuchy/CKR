/*
Exercise 3-6. 
Write a version of itoa that accepts three arguments instead of two. 
The third argument is a minimum field width; 
the converted number must be padded with blanks on the left if necessary to make it wide enough. 
*/

#include <stdio.h>
#include <strings.h>
#define MAXNUM 100

void itoa_buff (int n, char s[], int buffer);
void reverse (char s[]);

int main(){
    
    char str[MAXNUM];
    int buff = 14;
    int n = -2147483648;
    itoa_buff (n, str, buff);
    printf ("The outcome string is %s \n", str);
    return 0;

}

void itoa_buff (int n, char s[], int buffer)
{
    int i, sign;
    unsigned int un;
    if((sign = n) < 0)                  
        un = -n;
    else
        un = n;                         
    i = 0;
    do {                                
        s[i++] = un % 10 + '0'; 
    }         
    while((un /= 10) > 0);               
    
    if (sign < 0)
        s[i++] = '-'; 
    while (buffer > i)  {
        s[i++]= ' ';
    }
    
    s[i] ='\0';
    reverse(s);
}

void reverse (char s[]){

    int i, j;
    char c;

    for (i =0, j =strlen(s)-1; i < j; i++, j--) 
        c =s[i], s[i] =s[j], s[j] =c;

}
