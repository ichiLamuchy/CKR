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
#define MAXNUMLINE 15   // Maxmum number of lines

int getLine(char line[]);
void copyAppend (char to[], char from[], int j);

int main(){
    
    // should be 0;
    
    int i = 0;
    int len;
    char to [MAXALL];
    //char from [MAXLINE];            // the current line
    char line [MAXLINE];            // line to get, it will pass to char from []
    while ((len = getLine(line)) > 0){
        copyAppend (to, line, i);
        // need to get rid of '\0' if it is carry on
        i = len + i + 1;
    }
    --i;
    to[i] = '\n';
    printf ("%s", to);
    return 0;
}

/*

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


*/

void copyAppend (char to[], char from[], int j){
    int i = 0;
    while ((to[j]=from[i]) != '\0'){
        i++;
        j++;
    }
    to[j]='\n';
}
