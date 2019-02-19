#include <stdio.h>
#define MAXLINE 50      /* maximum input of size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main (){
    int len;            /* current line length */
    int max;            /* max line  length */
    char line[MAXLINE]; /* current input line - string */
    char longest[MAXLINE];   /* longest input line */

    max = 0;
    while ((len = getLine (line, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy (longest, line);
        }
    }
    if (max > 0){
        printf ("Longest line is %s, the length is %d \n", longest, max);
    }
    return 0;
}

/* getLine:     read a line return int - the length (changed from getline as stdio.h has a declared func with the same name) */
/* arg[0]: char a is line text, arg[1]: int lim is the maimum limit of the length of char a */
int  getLine(char a[], int lim){
    
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        a[i] = c;
    }
    if (c == '\n') {
        a[i] = '\0';  /* null */   
    }  
    return i;
}

/* copy:        copy from into to */
void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
    to[i] = '\0'; /* Let's add a null :)*/
}
