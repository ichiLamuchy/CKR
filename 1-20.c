#include <stdio.h>
/* detab programe - replace tub in the input to a set of numbrer of white space
should that n be parameter or variable
*/

#define MAXNUMBER 100 // Max number of input

int detab(char input[], int c, int lim);
void copyAppend(char to[], char from[], int j);

int main (){
    
    char line[MAXNUMBER];         /* current input line - string */
    char allLines[MAXNUMBER];     /* lappended input line */
    int len;                    /* line length by getchar */   
    int j;  
    j = 0;
    int c;
    // replacing tab to the numer of white space
    c = 2;
   
    while ((len = detab (line, c, MAXNUMBER)) > 0)
    {      
            copyAppend (allLines, line, j);
            // donot overwrite '\n'
            j = j + len + 1;   
    }
                      
    // overwrite '\n'
    --j;
    printf ("The last index is %d \n", j);
    allLines[j] = '\0';
    printf("%s \n", allLines);

    return 0;
}

/* 
detab - take input then print out the line replacing tab to 2 white spaces
arg[0] char array
arg[1] number of the white space per tab
arg[2] maxmum input text number
*/
int detab(char input[], int c, int lim){
    int i, j, k;
    // getchar up till eof or newline
    for (i = 0; i < lim - 1 && (k = getchar()) != EOF && k != '\n'; i++){
        // when tab detected        
        if (k == '\t'){
            for (j = 0; j < c; j++){
                input[i+j] = ' ';
            }
            i = i + c-1;
        }
        // otherwise just assign
        else {
            input[i] = k;
        }
    }
    input [i] = '\0';
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

