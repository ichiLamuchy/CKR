/*
Exercise 3-4. 
In a two's complement number representation, 
our version of itoa does not handle the largest negative number, 
that is, the value of n equal to -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs. 
*/

/*
Explanation on why largeset nagative number can not be handled on the existing itoa function:

In two's complement number replesents, negative number -n are presented as 2^(bits-1) - n 
it is the same as ~n + 1 :compliment number +1. (note: very right most 0 become 1 and all other 1 )

If you look at the formula, 
simply, the most possible largest -n exists on its own. 
No the abusolute number exist because it is always +1 on the negative number.


Solution: 
Simply use unsigned because other than largeest signed int, 
it will all can be caluculated to craete correct absolute value ok, 
and the smallest int would be calculated correctly in unsigned int.
*/

#include <stdio.h>
#include <strings.h>

#define MAXNUM 4

void itoa(int n, char s[]);
void itoa_max(int n, char s[]);
void reverse (char s[]);


int main (){

    char str[MAXNUM];
    int n = -2147483648;
    printf ("size of signed int is %lu \n", sizeof(n));
    itoa_max (n, str);
    printf ("The outcome string is %s \n", str);
    return 0;

}


/* itoa: original */ 

void itoa(int n, char s[])
{
    int i, sign;
    if((sign = n) < 0)                
        n = -n;                       
    i = 0;
    do {                                
        s[i++] =n % 10 + '0'; }         
    while((n /= 10) > 0);               
    if (sign < 0)
        s[i++] = '-'; s[i] ='\0';
    reverse(s);
}


/* itoa: can take -2147483648 */ 

void itoa_max(int n, char s[]){

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
        s[i++] = '-'; s[i] ='\0';
    reverse(s);
}


void reverse (char s[]){

    int i, j;
    char c;

    for (i =0, j =strlen(s)-1; i < j; i++, j--) 
        c =s[i], s[i] =s[j], s[j] =c;

}
