#include <stdio.h>

/*
Programe to hold long input
it should happen the closest nth column
*/

#define MAXNUMBER 100               // Max number of input
#define N 20                        // Max width of a line

int getLine(char input[], int lim);
int findspace(char input[], int i);
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
findspace:      Reading back word tp find white space from the nth charctor
arg[0]: char array - input text
arg[1]: current index 
*/
int findspace(char input[], int i){

    int j; 
    j = 0;
    // looks ugry but I dont like do loop
    while (input[i-j] != ' ' || input[i-j] != '\t'){
        j++;
        if (input[i-j] == ' ' || input[i-j] == '\t'){
            input[i-j] = '\n';
            return j;
        }
    }
    printf ("Cannot find a space, reconsider value of N");
    return -1;
}


/* 
    getLine:     read a line return int - the length 
    (changed the name from getline as stdio.h has a declared func with the same name) 
    arg[0]: char array - input text
    arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

int getLine(char input[], int lim){
    int i, j, k, l;
    l = 0;
    j = 0;
    // getchar up till eof or newline
    for (i = 0; i < lim - 1 && (k = getchar()) != EOF && k != '\n'; i++){

        // printf ("j is %d \n", j);  debug
        input[i] = k;
        if (j == N){
            l = (findspace(input, i));
            j = -1+l;
        }
        j++;    
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
