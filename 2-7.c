/*
Exercise 2-7. 
Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted 
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

unsigned invert (unsigned x, int p, int n);

int main(){

    // test on this - it should be 11010001 (209)
    unsigned x = 201;    // 11001001
    
    int p = 4;      
    int n = 2;
    
    printf ("the result is %d \n", invert (x, p, n));

    return 0 ;

}

unsigned invert (unsigned x, int p, int n){

    // version 2 just simply create 00011000 then ^ 
    // ((1<<n)-1)<<(p+1-n) --- 24
    printf ("test ((1<<n)-1)<<(p+1-n) is %d \n ", ((1<<n)-1)<<(p+1-n));
    printf ("test (((1<<n)-1)<<(p+1-n)) ^ x is %d \n ", (((1<<n)-1)<<(p+1-n)) ^ x);

    return (((1<<n)-1)<<(p+1-n)) ^ x;
}

/*
Take away from here - if you wanna use mask starting 111 like 11100111 then just use ^ 00011000

*/




