#include <stdio.h>
/* copy input to out put, print eof first*/

main(){
    int c;
    int eof = EOF; 

    printf ("EOF value is %2d\n", eof);
    while ((c=getchar())!= (0 & 1 & EOF)){
        putchar(c);
    }
}