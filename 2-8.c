/*
Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit position

oh no i think i created wrong way around wip then
*/


#include <math.h>
#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(){
   
    unsigned x = 201;    // 11001001
    
    int n = 3;
    printf ("result is %d \n",rightrot(x,n));
    return 0;

}


unsigned rightrot(unsigned x, int n){

    int bits_of_x = (int) log2 (x) + 1;

    // printf ("%d \n", bits_of_x);
    //  x >> (bits_of_x - n) this is 5 so get rid of all unnecessary
    // 00011111  --> ((1 << bits_of_x-n)-1) & x ---> 01001 -->9
    // printf ("test %d \n", (((1 << (bits_of_x-n) )-1) & x));
    // then push it back to (((1 << (bits_of_x-n))-1) & x) << n  ----> 01001000 ---72
    // printf ("test %d \n", (((1 << (bits_of_x-n))-1) & x) << n);
    // make now only n bits from left x >> bits_of_x-n  this should be 110 - 6
    // printf ("test %d \n", x >> (bits_of_x-n));
    // ^
    //printf ("test %d \n", ((((1 << (bits_of_x-n))-1) & x) << n) ^ (x >> (bits_of_x-n)));

    return ((((1 << (bits_of_x-n))-1) & x) << n) ^ (x >> (bits_of_x-n));

}

