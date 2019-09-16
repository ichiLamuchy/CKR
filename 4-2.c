/*
Exercise 4-2. Extend atof to handles cientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent

this should be able to achive by moving the . to left or right
but here I will just using math to do
*/

/*
what is signed exponent
2.3e-5, means 2.3 times ten to the minus five power, or 0.000023
4.5e6 means 4.5 times ten to the sixth power, or 4500000 which is the same as 4,500,000
*/

#include <stdio.h>
#include <ctype.h>

#define MAXNUM 100;

double atof_e(char s[]);

int main (){

    char str[] = "123.4e2";
    printf ("Print %f \n", atof_e(str));

}

/* 
atof: convert strings to double 
*/ 

double atof_e(char s[]){
    double val, power; 
    
    int i, sign;
    for(i=0; isspace(s[i]); i++); /* skip white space */

    sign =(s[i] == '-')? -1 : 1;  /* get a sign */
    if (s[i] == '+' || s[i] == '-') 
        i++;
    for (val = 0.0; isdigit(s[i]); i++){
        val =10.0 * val + (s[i] - '0'); /* everytime there is another char exisits it will be adding the times 10 value on it */
    }
    if (s[i] == '.')
        i++;
    for (power =1.0; isdigit(s[i]) && s[i] != 'e' && s[i] != 'E'; i++) {
        val =10.0 * val + (s[i] - '0'); /* exactly the same as what it happens on above fraction the varible power to make under fractiopn*/
        power *= 10.0;
    }
    /* once it his 'e' or 'E' there is a bit of redandancy */
    int sign2, j;
    double before_e;

    if (s[i] == 'e' || s[i] == 'E'){
        before_e = sign * val / power;    
        i++;

        sign2 =(s[i] == '-')? -1 : 1; 

        if (s[i] == '+' || s[i] == '-') 
            i++;
        for (j = 0; isdigit(s[i]); i++){       /* make it int */
            j =10 * j + (s[i] - '0'); 
        }
        while (j > 0 ){
            before_e *= 10;
            j--;
        }
        
        return before_e * sign2;
    }
    else
        return sign * val / power; 
}
