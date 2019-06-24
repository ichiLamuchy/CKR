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


    // step 1: x >> (p+1-n)  take off 3 bits so 11001  --- 25
    printf ("test x >> (p+1-n) is %d \n ", x >> (p+1-n));

    // step 2: flip ^  with 0011 so create mask (1<<n)-1  ----3
    printf ("test (1<<n)-1 is %d \n ", (1<<n)-1);

    // flip ^ 0010 ---26 ---> already flipped
     printf ("test (x >> (p+1-n)) ^ ((1<<n)-1) is %d \n ", (x >> (p+1-n)) ^ ((1<<n)-1));

    // put the space back to make xxxxx000 ---208
    printf("test ((x >> (p+1-n)) ^ ((1<<n)-1)) << (p+1-n) is %d \n ", ((x >> (p+1-n)) ^ ((1<<n)-1)) << (p+1-n));

    // now create 00000xxx - x & 00000111 -> (1<<(p+1-n))-1 ---7
    
    printf ("test ((1<<(p+1-n))-1 is %d \n ", (1<<(p+1-n))-1);

    // x &  ---1
    printf ("test ((1<<(p+1-n))-1 is %d \n ", x & ((1<<(p+1-n))-1));

    printf ("test (x & ((1<<(p+1-n))-1)) ^ (((x >> (p+1-n)) ^ ((1<<n)-1)) << (p+1-n)) is %d \n ", (x & ((1<<(p+1-n))-1)) ^ (((x >> (p+1-n)) ^ ((1<<n)-1)) << (p+1-n)));

return (x & ((1<<(p+1-n))-1)) ^ (((x >> (p+1-n)) ^ ((1<<n)-1)) << (p+1-n));


}




