#include <stdio.h>
#include <string.h>

// #include <typr.h>   // this has isapha but does not need unless you wanna define

/*
 Write an alternate version of squeeze (s 1,s2) that deletes
 each character in s 1 that matches any character in the string s2.
*/

#define LIM 10
#define MAX 20

int  get_line1(char a[], char b[]);
void c_squeeze (char str1[], char str2[]);

int main(){

    char ori_str[LIM];
    char remove_str[LIM];

    get_line1(ori_str, remove_str);
    c_squeeze(ori_str, remove_str);

    printf ("After squeezed out :  %s \n", ori_str);

    return 0;
}

/*
c_squeeze: deletes each character in str1 that matches any character in the string s2
arg[0]: char array  s１  - original string
arg[1]: char array  s2  - substring
*/

void c_squeeze (char str1[], char str2[]){

    int i, j, k, l, m;

    // cast to int from unsigned long
    l = (int)strlen(str2);
    m = 0;  /* flag for start copying over using j : it means this is after first match */

        /* check each character on str1 until terminator */
        for ( i = j = 0; str1[i] != '\0'; i++){
            /* check each characotor on s2 until teminator */
            for (k = 0; str2[k] != '\0'; k++){

                /* if 1st matched - get i value on j so that next round it will be copy over on jth index */
                if (str1[i] == str2[k] && m == 0){
                    j = i;
                    m = 1;
                    break;
                } 
                /* 
                do nothing if there is no match yet and they are not matched 
                or they are matched after first match
                */     
                else if( (str1[i] == str2[k]) || (str1[i] != str2[k] && m == 0)){
                    
                    break;
                }
                /*
                this is the last arond and it has not been evicted from the loop yet
                this is the one need to mainly copy over 
                */
                else if (str1[i] != str2[k] && m == 1  && (k == l-1)){                    
                    str1[j++] = str1[i];
                }
            }
        }
        str1[j++] = '\0';       
}

/* 
    getLine:     read a line return int - the length 
    (changed the name from getline as stdio.h has a declared func with the same name) 
    arg[0]: char array - input text
    arg[1]: int -  the maimum limit of the length of input text (arg [0]) 
*/

int  get_line1(char a[], char b[]){
    
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

