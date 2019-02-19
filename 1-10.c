#include <stdio.h>
/* sopy its input to output make visible on tab to \t blank space to \b backslash to \\ */
int main(){
    int c, tab, space, backslash;
    tab = 't';
    space = 'b';
    backslash = 92;
    while ((c = getchar()) != EOF){
        if (c == '\t'){
            putchar(backslash);
            putchar(tab);
        }
        /* this does not work unless you change raw input mode */
        else if (c == '\b'){
            putchar(backslash);
            putchar(space);
        }
        else if (c == '\\'){
            putchar(backslash);
            putchar(backslash);
        }
        else{
            putchar(c);
        }
    }
}
