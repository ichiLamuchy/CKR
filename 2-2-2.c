#include <stdio.h>

/*
Expand version of 2-2.c
create a loop equivelant to for the loop 
for (i<lim-1 && (c = getchar ()) != '\n' && c != EOF)
without using || or &&
it prints out each line using printf
*/

#define MAXLINE 10      // Maxmum number of input perline
#define MAXALL 100      // Maxmum nember of char can be store to all

int getLine(char line[]);
void copyAppend (char to[], char from[], int j);

int main(){
    
    int i = 0;
    int len;
    char to [MAXALL];
    char line [MAXLINE];            // line to get, it will pass to char from []
    while ((len = getLine(line)) > 0){
        copyAppend (to, line, i);
        
        i = len + i + 1;
    }
    --i;
    to[i] = '\n';
    printf ("%s", to);
    return 0;
}

/* 
    getLine:     read a line return int - the length 
    (changed the name from getline as stdio.h has a declared func with the same name) 
    arg[0]: char array - input text
    arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

int getLine(char line[]){
    int i = 0;
    int c;
    while (i < MAXLINE -2){
        if ((c = getchar()) != '\n'){
            if (c != EOF){
                line[i] = c;
                i++;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    
    line [i] = '\0';
    return i;
}

/* 
    copyAppend:     read a line append onto  
    arg[0]: char array - where appending to 
    arg[1]: char array - to get appended onto arg[0]
    arg[2]: int - index of arg[0] where appending from 
*/

void copyAppend (char to[], char from[], int j){
    int i = 0;
    while ((to[j]=from[i]) != '\0'){
        i++;
        j++;
    }
    to[j]='\n';
}
