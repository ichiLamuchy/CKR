/*
Write a function setbits(x,p,n,y) that returns x with the n bits t
hat begin at position p set to the rightmost n bits of y, 
leaving the other bits unchanged
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

unsigned c_bitwise_op (unsigned x, int p, int n, unsigned y);

int main (){

    // test on this - it should be 11011001 (217)
    unsigned i = 201;    // 11001001
    unsigned y = 27;    // 11011
    int p = 4;      
    int n = 2;
    
    printf ("the result is %d \n", c_bitwise_op (i,p,n,y));

    return 0 ;
}

unsigned c_bitwise_op (unsigned x, int p, int n, unsigned y){
    
    /*
    create mask 11100111 then use & x -> xxx00xxx
    extract n bits value from y then << p+1-n -> 000yy000
    xxx00xxx | 000yy000
    (when you need to convine just line up the mask either 0 (|) or 1 (&))
    */
    

    return ((x & ~(~(~0 << n) << (p+1-n))) | ((y & ~(~0<<n))<< (p+1-n)));
   

}
