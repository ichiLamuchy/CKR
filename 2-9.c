/* 
In a two's complement number system, x &.= (x-1) deletes the rightmost l-bit in x. 
Explain why. Use this observation to write a faster version of bitcount.


*/
#include <stdio.h>

int bitcount(unsigned x);
int bitcount_2(unsigned x);
int bitcount_3(unsigned x);

int main(){
    
    unsigned x = 1000;
    printf ("the return is %d \n", bitcount(x));
    printf ("the return 2 is %d \n", bitcount_2(x));
    printf ("the return 3 is %d \n", bitcount_3(x));

    return 0;
}

/* Apparently it works -  */

int bitcount(unsigned x)
{
    int b;
    for(b = 0; x !=0; x >>= 1) {
        if (x & 01){
        b++; 
        }
    }
    return b;
}


int bitcount_2(unsigned x){
    int count = 0;
    while (x != 0) {
        if (x &= (x-1)){
            count +=1;
        }
    }
    return count;
}

int bitcount_3(unsigned x){
    int count = 0;
    for (count = 0; x!=0; x &= (x-1)) {
         count ++;
        }
    
    return count;
}

