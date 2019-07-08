/* 
Write a function reverse (s) that reverses the character strings.
Use it to write programme which reverse the charactor string s 
in input a line at a time 
*/


#include <stdio.h>


#define MAXLINE 20              /* maximum input of size */
#define CHARNUM 1               /* Character Number - get at least 2 charactor */

int getLine(char line[], int maxline);
void reverse(char to[], char from[], int j);


/* print all input lines that are longer than 80 characters */
int main(){

    int len;                        /* line length by getchar */   
    char line[MAXLINE];             /* current input line - string */
    char reverseLines[MAXLINE];     /* lappended input line */
    int j;  
    j = 0;

    printf ("This will print out any input lines more than %d \n", CHARNUM);
    
    while ((len = getLine (line, MAXLINE)) > 0)
    {   
        if (len > CHARNUM ){
            reverse (reverseLines, line, len);            
        }
        printf("%s \n", reverseLines);

    }
        --j;
        reverseLines[j] = '\0';
        printf("%s \n", reverseLines);
    
    return 0;
}


/* 
getLine:     read a line return int - the length of input
(changed the name from getline as stdio.h has a declared func with the same name) 
arg[0]: char array - input text
arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/
int  getLine(char a[], int lim){
    
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){        
        a[i] = c;
    }
    // once excuted it will be added as ++i so no need to add extra
    a[i] = '\0';
    return i;
    
}

/* 
reverse:     get ricerse order of a string  
arg[0]: char array - reversed text
arg[1]: char array - original text
arg[2]: int - length of arg[1] 
*/
void reverse (char to[], char from[], int j){    
    int i;
    i = 0;
    to[j] = '\0';
    while (j != 0){
        j--;
        to[j] = from[i];
        i++;               
    }
     
}

