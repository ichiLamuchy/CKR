#include <stdio.h>
/* detab programe - replace tub in the input to a set of numbrer of white space
should that n be parameter or variable
*/

#define MAXNUMBER 100 // Max number of input

void detab(char input[], int c, int lim);

int main (){
    //char line [MAXNUMBER];

    int c;
    char arr[MAXNUMBER];
    //printf ("Please enter the number \nyou would like to convert a tab to whitespace? Press enter when you finish. \n");
    //c = getchar();
    //printf ("Thank you, the number you enter is %d, ", c-48);
    //printf ("Please now enter input you would like");
    
    c = 2;
    detab (arr, c, MAXNUMBER);
}

/* 
detab - take input then print out the line replacing tab to 2 white spaces
arg[0] char array
arg[1] number of the white space per tab
arg[2] maxmum input text number
*/
void detab(char input[], int c, int lim){
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
    printf ("Input are are %s, \n", input);   
}

