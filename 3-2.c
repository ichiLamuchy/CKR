/*
Write a function escape (s, t) 
that converts characters like new line and tab into visible escape sequences like
\n and \t as it copies the string t to s. Use a switch. 
Write a function for the other direction as well, converting escape sequences into the real characters
 */

/*
first write regular function that convert that to \t and \n if 
int i = '\n'


C has a variety of integer types: 
char (at least 8 bits), short (at least 16 bits), 
int (at least 16 bits), long (at least 32 bits). 
There are unsigned varieties of those. 
If you assign a value that is too large to a plain type, the results are undefined

char and int is pretty much the same a part from the six=ze of these


 A string can be initialized in different ways.

1. char str[] = "GeeksforGeeks";

2. char str[50] = "GeeksforGeeks";

3. char str[] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};

4. char str[14] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};

when you make a fuction you do mot need define the size of stri (char array) so that you can say char str[]


*/

#include <stdio.h>
#include <string.h>

#define MAXNUMBER 20  /* number of array */

void escape_1 (char str[], char strout[]);

int main (){

    char str [] = {'i', 'c', 'h', 'i', '\n'};
    char strout [MAXNUMBER];
    escape_1(str, strout);
    return 0;
}

void escape_1 (char str[], char strout[]){
    /* 
    condition to check the max elements on array
    */
    int i = 0;
    int n = strlen(str);  
    if ( n > MAXNUMBER)
        printf ("the strng is too big \n");

    for (int j = 0; j < n; j++){

        switch (str[j]){
            case '\n': 
                strout[i] = '\\';
                printf ("%c", strout[i]);
                strout[++i] = 'n';
                printf ("%c", strout[i]);
                break;
            case '\b':
                strout[i] = '\\';
                printf ("%c", strout[i]);
                strout[++i] = 'b';
                printf ("%c", strout[i]);
                break;
            default:
                strout[i] = str [j];
                printf ("%c", strout[i]);
                break;
        }    
    }

}

