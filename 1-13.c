#include <stdio.h>
#define VLINE 100 /* to be print out "|" */
#define NEXT__VLINE 50  /* to be print out " "  once then "|" after that*/

/* write histogramme of the lengh of words in its input*/
int main(){

    int i, k, l, m, c, wc, maxvalue;
    k = c = wc = l = m = maxvalue = 0;
    int arr [20];

        for (i = 0 ; i < 20; i++){
            arr[i] = 0;
        }
        
        while ((c = getchar()) != EOF){
            // count any input
            ++wc;
            // prepare array for printing histograme
            if (c == ' ' | c == '\n' | c == '\t' ){            
                --wc;
                if (wc != 0){
                    ++arr [wc * 2];
                    k = arr [wc * 2];
                    if (maxvalue < k){
                        maxvalue = k;  
                    }
                    wc = 0;
                }
            }        
        }
        
    printf ("this is maxvalue %d \n", maxvalue);

    for (m = maxvalue; m >= 0; --m){
        for (l = 0; l < 20; ++l){

            if (arr[l] == VLINE ){
                printf ("|");
            }

            else if (arr[l] == NEXT__VLINE ){
                printf (" ");
                arr[l] = VLINE; 
            }
            
            else if (arr[l] == m && m != 0 ){
                printf ("_");                    
                if (arr [l - 1] == 0){
                    arr [l - 1] = VLINE;
                }
                if (arr [l + 1] == 0){
                    arr [l + 1] = NEXT__VLINE;
                }
            }
            else{
                printf (" ");
            }                
        }
        printf ("\n");
    }
}

