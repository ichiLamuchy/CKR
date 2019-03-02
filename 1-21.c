#include <stdio.h>
#include <stdbool.h>

/* 
Create entab programe - replace 4 white space in the input to a tub
*/

#define MAXNUMBER 100               // Max number of input
#define WS 4                        // white space

int getLine(char input[], int lim);
bool entab(char input[], int c, int i);
void copyAppend(char to[], char from[], int i);


int main(){
    
    char line[MAXNUMBER];               // current input line - string 
    char allLines[MAXNUMBER];           // lappended input line 
    int len;                            // line length by getchar  
    int j;  
    j = 0;
   
    while ((len = getLine (line, MAXNUMBER)) > 0)
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
    detub:     switch tub to w number of white spaces
    (changed the name from getline as stdio.h has a declared func with the same name) 
    arg[0]: char array - input text
    arg[1]: current index number
    arg[2]: number of the white space per tab
*/

bool entub (char input[], int i, int c){
    int j;
    j=1;
    while (j < c && input[i-j] == ' '){
        j++;
        if (j == c){

            return true;
        }
    }
    return false;
}

/* 
detab - take input then print out the line replacing tab to 2 white spaces
arg[0] char array
arg[1] maxmum input text number
*/

int getLine(char input[], int lim){
    int i, k;
    // getchar up till eof or newline
    for (i = 0; i < lim - 1 && (k = getchar()) != EOF && k != '\n'; i++){
        // when tab detected        
        if (k == ' '){
            // changer tab to 
            if (entub (input, i, WS)){
                i = i - WS + 1;
                input[i] = '\t';
            }
            else {
                input[i] = k;
            }
            
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

