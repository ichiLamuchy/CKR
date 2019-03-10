#include <stdio.h>

/*
create a loop equivelant to for the loop 
for (i<lim-1 && (c = getchar ()) != '\n' && c != EOF)
without using || or &&
*/

#define MAXNUM 10
int main(){
    
    // should be 0;
    int i=0;
    int c=0;
    
    while (i < MAXNUM -1){
        while ((c = getchar()) != '\n'){
            while (c != EOF){
                i++;
            }
        }
    }
    return 0;
}
