/*
Write a function setbits(x,p,n,y) that returns x with the n bits t
hat begin at position p set to the rightmost n bits of y, 
leaving the other bits unchanged
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
/*
WIP note: 

this is also useful http://joequery.me/notes/learning-c-4/


the add that onto X for position P

1: use getbits ish function to extract the n bits from y  & ~(~0 << n) is the filter so Y & ~(~0 << n) 
2: the aobve will need some 0 at the end (<<) when last step taking place
3: find position p (p+1), and find number of bits on suffix after the nbits end - p+1-n (this will be applied on step 2)
4: use "|" to make the nbits from posiopn p to be 1 and followed by p+1-n bits on 0
5: how to achive step 4 is first convert the to (~(~0 << n))<< p+1-n  do if n is 4 and p is 6 it should be 00001111000
6: x | (~(~0 << n))<< p+1-n to get ready on compare to step 2 out come
7: then bitwise operation of the step 6 & 2 (x | (~(~0 << n))<< p+1-n) & (y  &  ~(~0 << n)) << (p+1-n)) in theory
*/


void c_test_bitwise_op (unsigned x, int p, int n, unsigned y);

int main (){

    // test on this - it should be 11011001 (217)
    unsigned i = 201;    // 11001001
    unsigned y = 27;    // 11011
    int p = 4;      
    int n = 2;
    
    c_test_bitwise_op (i,p,n,y);
    return 0 ;
}

void c_test_bitwise_op (unsigned x, int p, int n, unsigned y){

// steps to take
// 1 - with x we make xxx11xxx 

// 1-1 we create 00011000 filter  - prefix 000 + nbits of 1 + suffix number of y
printf ("(~(~0 << n))<< (p+1-n) is %d \n", (~(~0 << n))<< (p+1-n)); 
// 1-2 then use or (|) to create the result
printf ("x | ((~(~0 << n))<< (p+1-n)) is %d \n", x | (~(~0 << n))<< (p+1-n)); 

// 2 - with y, we wanna create 111xx111 where xx is the value you extract from y

// move the value need to copyonto x to be on the right position then 

// 2-1 to do it, we need to craete 11100111 filter to do 000xx000 to and (&)
// 2-1-1 create 11100000
printf ("(~0 << (p+1))is %d \n", (~0 << (p+1)));


// 2-1-2 create 000000111
printf ("(~0 << (p+1-n) is %d \n", (~0 << (p+1-n)));

// or (|) operate on 11100000 | 00000111 should gives you 11100111 this is filter to get a value
printf ("(~0 << (p+1)) | (~0 << (p+1-n)) is %d \n", (~0 << (p+1)) | (~0 << (p+1-n)));

// 2-2 to create 000xx000 

// 2-2-1 create 00000011 by ~(~0<<n)
printf ("~(~0<<n) is %d \n", ~(~0<<n));
// 2-2-2 y & 00000011 -- extract value of nbits from y
printf ("(y & (~(~0<<n))  is %d \n", (y & (~(~0<<n))));
// 2-2-3  ((y & 00000011 )<< (p+1-n)) - push it to the right place

printf ("(y & (~(~0<<n))<< (p+1-n)is %d \n", (y & (~(~0<<n)))<< (p+1-n));

// 3 combine to gether 11100111  & ((y & 00000011 )<< (p+1-n)) - push it to the right place
printf ("(x | (~(~0 << n))<< (p+1-n))& (y & (~(~0<<n))<< (p+1-n)) is %d \n", (x | (~(~0 << n))<< (p+1-n))& (y & (~(~0<<n)))<< (p+1-n));

printf ("done it should be 217 \n");

}
