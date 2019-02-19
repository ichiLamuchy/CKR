/* write histogramme of frequesncy of charactors in its input*/
// get input
// if it is alphabet then add it on to the appropriate index
# include <stdio.h>
main(){
    int i, j, k, l, m, c, maxvalue, maxindex;
    k = c = l = m = maxvalue = maxindex = 0;
    // 26 * 2
    int arr [54];

        for (i = 0 ; i < 54; i++){
            arr[i] = 0;
        }
        
        while ((c = getchar()) != EOF){
            // count if it is alphabet - make all to capital askii number
            if (c >= 97 && c <= 122){
                c = c -32;
            }
            // if alphabet
            if (c >=65 && c <=90){
                // make a space on index 0
                c = c - 65 + 1;
                // add number 
                ++arr [c * 2];
                k = arr [c * 2];
                if (maxvalue < k){
                    maxvalue = k;
                    maxindex = k * 2;    
                }
            }                  
        }
        
    printf ("this is maxvalue %d \n", maxvalue);

    for (m = maxvalue; m >= 0; --m){
        for (l = 0; l < 54; ++l){

                if (arr[l] == 100 ){
                    printf ("|");
                }

                else if (arr[l] == 50 ){
                    printf (" ");
                    arr[l] = 100; 
                }
                else if (arr [l] == m && m == 0){
                    printf (" ");
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

