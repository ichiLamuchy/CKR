/*
Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
*/


#include <stdio.h>

float convertFtoC (float fah);

int main(){
    float fah;
    int lower, upper, step;

    /* Limit on Fahrenheit and a step declearation*/
    lower = 0;
    upper = 300;
    step = 20;

    fah = lower;

    printf ("fer    cel \n");
    while (fah <= upper){
        
        printf ("%3.0f %6.1f \n", fah, convertFtoC (fah));
        fah = fah + step;
    }
    return 0;
}

// declare function conversion
float convertFtoC (float fah){
    return (5.0/9.0) * (fah-32.0);
}
