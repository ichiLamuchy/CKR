/* 
print all input lines but get rid of trails 
*/


#include <stdio.h>

#define MAXLINE 60              /* maximum input of size */
#define CHARNUM 0               /* Minimum Character Number set 0 to inhibit any empty line */

int getLineNoTrails(char line[], int maxline);
void copyAppend(char to[], char from[], int j);

int main(){

    int len;                    /* line length by getchar */   
    char line[MAXLINE];         /* current input line - string */
    char allLines[MAXLINE];     /* lappended input line */
    int j;  
    j = 0;

    printf ("This will print out any input lines without whitespace or tub trails \n");
    
    while ((len = getLineNoTrails (line, MAXLINE)) > 0)
    {      
            copyAppend (allLines, line, j);
            // printf ("%d \n", j); 
            // donot overwrite '\n'
            j = j + len + 1;   
    }
    if (j<3){
        printf ("Error: please put input more than 3 \n");
    }
    else{                       
        // printf ("%d j is \n", j);
        // printf ("%d len is \n", len);
        // over write '\n'
        --j;
        printf ("%d \n", j);
        allLines[j] = '\0';
        printf("%s \n", allLines);
    }
    return 0;
}


/* 
getLineNoTrails:     read a line return int - the length without any ' ' or '\t' on trail
(changed the name from getline as stdio.h has a declared func with the same name) 
arg[0]: char array - input text
arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/
int  getLineNoTrails(char a[], int lim){
    
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        a[i] = c;
    }
    --i;
    while ((a[i] == ' ') || (a[i] == '\t')){
            a[i] = '\0';
            i--;
    }
    // return the length 
    // add '\0' for all
    i++;
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
