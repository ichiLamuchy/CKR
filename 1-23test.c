#include <stdio.h>

/*
Programe to hold long input
it should happen the closest nth column
*/

#define MAXNUMBER 100               // Max number of input

void get_input(char input[], int lim);
void search_end_comment (int a, int b);
void check_quote (int c, int quote);

int main(){
    
    char line[MAXNUMBER];               // current input line - string 

    get_input (line, MAXNUMBER);
    printf("%s \n", line);

    return 0;
}


/* 
    get_input:     read inputs  
    
    arg[0]: char array - input text
    arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

void get_input(char input[], int lim){
    int i, quote, c, d;
    
    quote = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++){
        // check quote
        if (c == '\'' || c == '"' ){
            if (quote == 1){
                quote = 0;
            }
            else {
                quote = 1;
            }    
        }

        if ( c == '/' && !quote ){
            if ((d = getchar()) == '*'){
                search_end_comment (d, c);
                i--;
            }
            else{
                input[i] = c;
                i++;
                input[i] = d;
            }
        }        
        else {
            input[i] = c;
        }
    }
    input [i] = '\0';
    
}

/* 
    search_end_comment:     serch the end of comment 
    
    They camn be omit
    arg[0]: int - '*'
    arg[1]: int - '/'
*/
void search_end_comment (int a, int b){     
    int c, d;
    // get first 2
    c = getchar();
    d = getchar();

    while (c != a || d != b){
        d = getchar();
        if (d == a){
            c = d;
        }        
    }
}

