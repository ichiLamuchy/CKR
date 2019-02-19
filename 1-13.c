/* write histogramme of the lengh of words in its input*/
# include <stdio.h>
int main(){
    int i, j, k, l, m, c, wc, maxvalue, maxindex;
    k = c = wc = l = m = j = maxvalue = maxindex = 0;
    int arr [20];

        for (i = 0 ; i < 20; i++){
            arr[i] = 0;
        }
        
        while ((c = getchar()) != EOF){
            // count number of word
            ++wc;
            if (c == ' ' | c == '\n' | c == '\t' ){            
                --wc;
                if (wc != 0){
                    ++arr [wc * 2];
                    k = arr [wc * 2];
                    if (maxvalue < k){
                        maxvalue = k;
                        maxindex = wc * 2;    
                    }
                    wc = 0;
                }
            }        
        }
        
    printf ("this is maxvalue %d \n", maxvalue);

    for (m = maxvalue; m >= 0; --m){
        for (l = 0; l < 20; ++l){

                if (arr[l] == 100 ){
                    printf ("|");
                }

                else if (arr[l] == 50 ){
                    printf (" ");
                    arr[l] = 100; 
                }
                
                else if (arr[l] == m ){
                    printf ("-");                    
                    if (arr [l - 1] == 0){
                        arr [l - 1] = 100;
                    }
                    if (arr [l + 1] == 0){
                        arr [l + 1] = 50;
                    }
                }
                else{
                    printf (" ");
                }
                
        }
        printf ("\n");
    }
}

