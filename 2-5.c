/*
Write the function any (s 1, s2 ), which returns the first location
in the string s 1 where any character from the string s2 occurs, or -1 if s 1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.
*/


#include <stdio.h>
#include <strings.h>

#define LIM 20

int get_line1(char a[], char b[]);
int c_any (char str1[], char str2[]);

int main(){

    char ori_str[LIM];
    char match_str[LIM];
    get_line1(ori_str, match_str);

    printf ("1st index of matched char on string 1 is :  %d \n",  c_any(ori_str, match_str));

    return 0;
}

int c_any (char str1[], char str2[]){

    int i, k, found;
    found = 0;  /* flag for string match found */

        /* check each character on str1 until terminator */
        for ( i = 0; str1[i] != '\0'; i++){
            /* check each characotor on s2 until teminator */
            for (k = 0; str2[k] != '\0'; k++){

                /* if 1st matched - return i  */
                if (str1[i] == str2[k] && found == 0){
                    found = 1;
                    return i;
                } 
            }
        }
    return -1;        
}

/* 
getLine:     read a line return int - the length 
(changed the name from getline as stdio.h has a declared func with the same name) 
arg[0]: char array - input text
arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

int get_line1(char a[], char b[]){
    
    int c, i, k;
    printf ("Please type the original \n");
    for (i = 0; i < LIM - 1 && (c = getchar()) != EOF && c != '\n'; i++){       
        a[i] = c;
    }
    /* once excuted it will be added as ++i so no need to add extra */
    a[i] = '\0';

    printf("Original Str: %s \n", a);
    printf ("Please type the removing chars \n");

    for (i = 0; i < LIM - 1 && (k = getchar()) != EOF && k != '\n'; i++){       
        b[i] = k;
    }
    
    printf("Removing Str: %s \n", b);
    return i;
}
