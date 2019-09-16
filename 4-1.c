/*
Exercise 4-1. Write the function strrindex (s, t), which returns the position
of the rightmost occurrence of t in s, or - 1 if there is none
 */

#include <stdio.h>
#include <strings.h>

#define MAXNUM 30

int strindex1 (char str[], char t);

int main (){

    char str [MAXNUM] = "tararaloa";
    char t = 'a';

    printf ("the index is %d \n", strindex1(str, t));
}

int strindex1 (char str[], char t){

    int j = -1;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == t){
            j = i;

            printf ("i is %d \n", i);
            printf ("j is %d \n", j);
        }
    }

    return j;
}

