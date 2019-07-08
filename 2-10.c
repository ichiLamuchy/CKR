/*
Rewrite the function lower,which converts uppercase letters
to lowercase, with a conditional expression instead of if-else. 
*/


#include <stdio.h>

int lower_basic(int c);
int lower_new(int c);

int main(){
/* test */
    int c = 'O';
    printf ("This is %c \n", lower_basic(c));
    printf ("This is %c \n", lower_new(c));
}

/* 
lower: convert c to lower case basics 
*/

int lower_basic(int c){
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    else {
        return c;
    }
}

/* 
lower: convert c to lower case - conditinal expression
*/ 

int lower_new(int c){
    return (c >= 'A' && c <= 'Z')? c + 'a' - 'A': c;
}
