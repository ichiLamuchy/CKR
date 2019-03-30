#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*
Write a function htoi
which convert strings of hexadecimol digits to(incl optional 0x and 0X)
into equivelant interger value. 
The allowed digits are 0 through 9, a through f, A through F
*/

/*
remember '' is a char,  "" is char []
*/

/* 
rules of hex 
starting with /x or 0x or 0X
*/


/*


int isxdigi(int c)
https://www.tutorialspoint.com/c_standard_library/c_function_isxdigit.htm

*/

int hextoi (char str1 []);
int is_hex (char str1[]);

int main(){
    
    char str1 [] = "0xa3";
    
    printf ("%d \n", hextoi(str1));
    
    return 0;
}


// create second finction first
// both char is hexdesmo without the prefix of indication. this will befinally changed once is_hex function created
// 
int hextoi (char str1 []){
    int i;
    int len = strlen (str1);
    int j = 0;
    int add_all = 0;

    if ((i = is_hex(str1) == 0){
        printf ("This is not hexdecimol");
    }
    
    for (i = is_hex(str1); i < len; i++){
        /* convert from ascii to real number if it is 1-9 (str1 [i] -48) */
        if (isdigit(str1[i])){
            j = str1[i] - 48;
        }
        else if {
            /* to simplyfy, make all lower case and convert to hex number in decimol*/
            j =  tolower (str1[i]);
            /* convert a-f to 10-15 */
            j = j - 87;
        }
        else {
            printf ("this van not be valid hexdecimol. It contents value other than 1-9 and a-f or A-F");
        }
        /* convert what it should be power of -len-i-1*/
        add_all += j * pow (16, len-i-1);
        printf ("i is %d \n", i);
        printf ("%d \n", add_all);
    }
     //printf ("%d \n", add_all);
     return add_all;
}

int is_hex (char str1[]){

    //int i =0;
    int j = 0;
    /*
    if (str1 [0]== '\x'){
        j = 1;

        // will need impliment ssome exception and error handler
    } else */
    if (str1[0] == '0' && (str1[1]== 'x' || str1[1]== 'X')){
        return j;
    }
    else {
        return 0;
    }

}






// PLAN ------
//what need to be done.

// define HEXNUM 16
// start reading string char[] = "" on main - this can be taken from stdin if needed to be

// on is_hex finction for true or false / retutn str with out the mark of it
// if the first one is /x -> defined as hex -> make a true mark on is_hex this defined as false on intialisation
// if the first one is 0 and second one is x or X    if (num[i] == 0 && (num[i+1]== 'x' || num[i+1]== 'X')) mark is_hex to true
// next condition if is_hex  then convert so 

// second function to convert hex to int
// tale len of the string using strlen then loop  (k)
// can i use power you can use pow from math.h
// for loop to go num [j] * pow (16, k) where k is decreasing number -> len - j -1
