/*
Write a program to determine the ranges of char, short, int, 
and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct computation.

*/


#include <stdio.h>
#include <limits.h>
#include <float.h>

long power_of(long base, long power);

int main (){

    // i get size of each then  to power of the size to compute if anything is missing

    printf ("Value of each types \n");
    printf ("\n");

    // signed char
    printf ("Max signed char value is %d \n", SCHAR_MAX );
    printf ("Minimum signed char value is %d \n", SCHAR_MIN );
    printf ("\n");

    // unsigned char
    printf ("Max unsigned char value is %d \n", UCHAR_MAX );
    printf ("Minimum value of unsigned char is %ld \n", UCHAR_MAX-(power_of (2, (sizeof(unsigned char)) * 8)-1));
    printf ("\n");

    // int
    printf ("Max int value is %d \n", INT_MAX );
    printf ("Minimum value of int is %ld \n", INT_MAX - (power_of(2, (sizeof(int)) * 8)-1));
    printf ("\n");

    // unsigned int
    printf ("MAX value of unsigned int is %u \n", UINT_MAX);
    printf ("Minimum value of unsigned int is %ld \n", UINT_MAX - (power_of(2, (sizeof(unsigned int)) * 8)-1));   
    printf ("\n");

    // short
    printf ("Max short int value is %d \n", SHRT_MAX );
    printf ("Minimum short int value is %d \n", SHRT_MIN);
    printf ("\n");

    // unsigned short
    printf ("Max unsigned short int value is %d \n", USHRT_MAX );
    printf ("Minimum unsigned short int value is %ld \n", USHRT_MAX-(power_of(2, (sizeof(unsigned short)) * 8)-1));    
    printf ("\n");

    // signed long
    printf ("Max long int value is %ld \n", LONG_MAX );
    printf ("Minimum long int value is %ld \n ", LONG_MIN);
    printf ("\n");

    // unsigned long
    printf ("Max unsinged long value is %lu \n", ULONG_MAX );
    printf ("Minimum unsigned long int value is %ld \n ", ULONG_MAX-(power_of(2, (sizeof(unsigned long)) * 8)-1));
    printf ("\n");

    return 0;

}

// using long as the value goes way far for int
 long power_of(long base, long power){
        int i = 0;
        int j = base;
        
        for (i = 0; i < power -1; i++){
            base = base * j;
            //printf ("%ld \n", base);
        }
        return base;
    }
