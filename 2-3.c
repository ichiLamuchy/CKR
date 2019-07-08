#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 10 /* Maximum number of string */

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


/* also define max number of imput */


int hextoi (char str1[]);
int is_hex (char str1[]);

int main(){
    
    // example imput
    char str1[MAX];
    str1 = "Xcc1";
    
    if (hextoi(str1) == -1){
        return -1;
    }
    printf ("%d \n", hextoi(str1));
    return 0;
}

/*
takes a char[] to convert from hex decemol to equivelant int
If it contents the invalid charator on the string, it will throw a erorr


// Test to carryed out
// put str not starting 0x or 0X   ----
// put str starting 0x              ----
// put str starting 0X              ----

// put star starting 0x or 0X but none hex charactor ther such as h  ----
// put empty strings
// out dufferent data type


arg[0]; char[]
*/ 
int hextoi (char str1[]){
    int i;
    int len = strlen (str1);

    int j = 0;
    int add_all = 0;

    if ((i = is_hex(str1)) == 0){
        printf ("This is not hexdecimol \n");
        return -1;
    }
    /*
    else if ((i = is_hex(str1) == 1){
        then manupitrate with the string

        }
    }
    */

    // if starting with "0x" or "OX", i should be 2
    else {
        for (i = is_hex(str1); i < len; i++){
            /* convert from ascii to real number if it is 1-9 (str1 [i] -48) */
            if (isdigit(str1[i])){
                j = str1[i] - 48;
            }
            else {
                /* to simplyfy, make all lower case and convert to hex number in decimol*/
                j =  tolower (str1[i]);

                if ( j < 97 || j > 102 ){
                    printf ("Error: This is not valid hexfecimol string, It contents value other than digits, a-f or A-F  \n");
                    return -1;
                }
                /* convert a-f to 10-15 */
                j = j - 87;
            }
            /* convert what it should be power of -len-i-1*/
            add_all += j * pow (16, len-i-1);
            printf ("i is %d \n", i);
            printf ("%d \n", add_all);
        }
    }
     //printf ("%d \n", add_all);
     return add_all;
}


/*
check if it is starting "\x",  "0x" or "OX"
if it sterts with "\x" ----- here you need to figure out hopefully does the conversion straight away
if it starts with "0x" or "0X" then gives 2 for now


plan 1: 
if the \x - then return 1 so that existing function can sort it out
if 0x or 0X then return 2
else return 0

plan 2:
the return need to be string as int can be any of actual number on but we will figure out once we could see 

*/

int is_hex (char str1[]){

    //int i =0;
    int j = 0;

    if (str1[0] == '0' && (str1[1]== 'x' || str1[1]== 'X')){
        j = 2;
        return 2;
    }
    else {
        return 0;
    }

}
