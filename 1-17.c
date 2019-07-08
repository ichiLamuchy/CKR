/* 
print all input lines that are longer than 80 characters 
*/


#include <stdio.h>
#define MAXLINE 20              /* maximum input of size */
#define CHARNUM 3               /* Character Number */

int getLine(char line[], int maxline);
void copyAppend(char to[], char from[], int j);

int main(){

    int len;                    /* line length by getchar */   
    char line[MAXLINE];         /* current input line - string */
    char allLines[MAXLINE];     /* lappended input line */
    int j;  
    j = 0;

    printf ("This will print out any input lines more than %d \n", CHARNUM);
    
    while ((len = getLine (line, MAXLINE)) > 0)
    {   
        if (len > CHARNUM){
            copyAppend (allLines, line, j);
            // printf ("%d \n", j); 
            // donot over weite '\n'
            j = j + len + 1;
        }
    }
    if (j==0){
        printf ("Error: please put input more than 3 \n");
    }
    else{                       
        // printf ("%d j is \n", j);
        // printf ("%d len is \n", len);
        // over write '\n'
        --j;
        allLines[j] = '\0';
        printf("%s \n", allLines);
    }
    return 0;
}


/* 
getLine:     read a line return int - the length 
(changed the name from getline as stdio.h has a declared func with the same name) 
arg[0]: char array - input text
arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

int  getLine(char a[], int lim){
    
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        // printf ("%d, \n", i);
        
        a[i] = c;
        //printf ("%c, \n", a[i]);
    }
    // once excuted it will be added as ++i so no need to add extra
    a[i] = '\0';
    return i;    
}


/* 
copyAppend:     read a line append onto  
arg[0]: char array - where appending to 
arg[1]: char array - to get appended onto arg[0]
arg[2]: int - index of arg[0] where appending from 
*/

void copyAppend (char to[], char from[], int j){    
    int i;
    i = 0;
    while ((to[j] = from[i]) != '\0'){
        ++i;       
        ++j;
    }
    to[j] = '\n';   
}

