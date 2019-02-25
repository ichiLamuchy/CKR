#include <stdio.h>


#define MAXNUMBER 100 // Max number of input



int main (){
    //char line [MAXNUMBER];

    int c;

    printf ("Please enter the number \nyou would like to convert a tab to whitespace? Press enter when you finish. \n");
    c = getchar();
    printf ("Thank you, the number you enter is %d, ", c-48);

    printf ("Please now enter input you would like");

    c = c-48;

    char arr [20];
    int i;
    i= 0;
    arr[i]='s';
    i ++;
    int j;
    for (j = 0; j < c; j++){
        arr [i+j] = ' ';
    }
    i = i + c;
    arr [i]='e';
    printf ("array are %s, \n", arr);



}
