#include <stdio.h>
/* Count tabs blanks and new lines */

int main(){
    int c, i;
    i = 0;
    while ((c = getchar())!= EOF)    
        if (c =='\t' | c=='\n' | c== ' '){
            ++i;
        } 
    printf ("%d \n", i);   
}
