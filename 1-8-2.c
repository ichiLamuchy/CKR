#include <stdio.h>
/* Count tabs blanks and new lines dont know if excute */
int main(){

    int c, i;
    i = 0;
    while ((c = getchar()) != EOF )
    /* 9, 10, 32 is askii of tab, nl, space */
        if (c ==  9 | c == 10 | c ==32 ){
            ++i;
        } 
    printf ("%d \n", i);   
}
