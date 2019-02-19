#include <stdio.h>

main(){
    int c, i;
    char str [100];

    for  (i = 0; (c = getchar()) != EOF; i++){
        
        if ( c == '\t' | c == '\n' | c == ' '){
            str[i]= '\n';                        
        }
        else {
            str[i]= c;
        }
    }
    printf ("%s \n", str);
}