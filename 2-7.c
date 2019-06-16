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
    unsigned x = 106;    // 11001001
    
    int p = 4;      
    int n = 2;
    
    printf ("the result is %d \n", invert (x, p, n));

    return 0 ;


}

unsigned invert (unsigned x, int p, int n){

    // do the same p is 4 n is 2

    // extract the value of n bits from position p

    // make a mask 0011111 
    //~(~0 << (p+1))
    
    // & x to get extract p+1 BITS - 0001010
    // (~(~0 << (p+1))) & x 

    // flip ~ let's say 00010101  (nbits nit is 10) so it become 1110101 - we need the first 2 bits to be 0
    //  ~((~(~0 << (p+1))) & x)

    // use the 0011111 mask again for AND op 1110101  so it become 0010101 - 21
    // ~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x)

    printf ("test ~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x) is %d \n ", ~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x));

    // >> get rid of p+1-n then get it back << p+1-n -> 00001000 
    // (~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x)) >> (p+1-n) << (p+1-n)) --- 000nn000 = 0010000 -16
    printf ("test (~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x)) >> (p+1-n) << (p+1-n)) is %d \n", (~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x)) >> (p+1-n) << (p+1-n));
    // 
    // another bits to make xxx00xxx
    // create 11100111 (231) 
    printf ("test (~(~0 << n)<<(p+1-n)) is %d \n ", (~(~0 << n)<<(p+1-n)));
    printf ("test ~(~(~0 << n)<<(p+1-n)) is %d \n ", ~(~(~0 << n)<<(p+1-n)));
    // Starting 11 does not work, need another way

    //then OR x to xxx00xxx
    // ~(~(~0 << n)<<(p+1-n)) | x

    // then you can hhave 000nn000 or xxx00xxx




    //( ((~(~0 << (p+1))) & ~((~(~0 << (p+1-n))) & x)>>p+1-n) <<p+1-n) | (~(~(~0 << n)<<(p+1-n)) | x)


    //return (~(~0 << (p+1)) &  ~((~(~0 << (p+1))) & x)) >> (p+1-n) << (p+1-n)) | (~(~(~0 << n) << (p+1-n)) | x));


    // some note
    // nbits -> 2 to the power of n -1
    // 1<<2   ---> 100
    // 1<<n - 1   ---> 011
 
    // n = n | (n>>1) ->this way expand the mask 1
    // 


    // create masks 
    // 
return 0;


}




