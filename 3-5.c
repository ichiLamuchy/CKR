/* 
Exercise3-5.Write the function itob(n,s,b) 
that converts the integer n into a base b character representation in the string s. 
In particular, itob (n, s, 16) formats n as a hexadecimal integer in s.

conversting int n base b then print out 
*/

/* to do : there is no error fall back */ 



#include <stdio.h>
#include <strings.h>

#define MAXNUM 100

void itob(int n, char s[], int b);
void reverse (char s[]);

int main (){

    int n = 17;
    int b = 3;
    char str [MAXNUM];
    itob (n, str, b);
    printf ("The outcome string is %s \n", str);
    return 0;

}


void itob(int n, char s[], int b) {

    /* new set of num */
    char newnum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    /* base should be between 2-z */
    if ( n < 2 || n > 34){
        printf ("Error, cannot excute");
        //return -1;
    }

    int i;                    
    i = 0;
    do { 
        s[i++] = newnum[n % b];  
    }         
    while((n /= b) >= b);               
    
    s[i++] = '1'; 
    s[i] ='\0';

    reverse(s);
}

void reverse (char s[]){

    int i, j;
    char c;

    for (i =0, j =strlen(s)-1; i < j; i++, j--) 
        c =s[i], s[i] =s[j], s[j] =c;

}

