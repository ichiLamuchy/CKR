#include <stdio.h>
/* acopy input to ouput - replace one of more blank by a single blank*/

int main(){
    int c, c2;
    int eof = EOF; 

    printf ("EOF value is %2d\n", eof);
    while ((c=getchar())!= EOF){
        /* check if it is blank then use loop to eliminate it */
        // need to be eof twice
        putchar(c);
        if (c == ' '){
            while ((c2=getchar()) == ' ')
            ; 
            c = c2;
            putchar(c);           
        }        
    }
}

