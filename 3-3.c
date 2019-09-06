/*
Exercise 3-3. 
Write a function expand (s1, s2) 
that expands shorthand notations like a - z in the string s 1 into the equivalent complete list abc ... xyz in s2. 
Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-zO-9 and -a-z. 
Arrange that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#include <string.h>

#define MAXNUMBER 100  /* number of array */

void expand1(char s1[], char s2[]);

int main (){
    char s1[] = "1-5a-c";
    char s2[MAXNUMBER];

    printf ("char s1 is %s \n", s1);

    expand1(s1, s2);

    printf ("char s2 is %s \n", s2);
}

void expand1(char s1[], char s2[]){

int j, n, len;
int c = 0;     /* charactor already assigned on  */
int whattype = 0; /* this indicate type either 1-digit, 2-capital letter, 3-small letter */
int i = 0;

n = strlen (s1);
    while(i < n){

        if ((s1[i] >= '0' && s1[i] <= '9') && (s1[i+2] >= '0' && s1[i+2] <= '9')){
            whattype = 1;
        }
        else if ((s1[i] >= 'A' && s1[i] <= 'Z') && (s1[i+2] >= 'A' && s1[i+2] <= 'Z')) {
            whattype = 2;
        }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') && (s1[i+2] >= 'a' && s1[i+2] <= 'z')){
            whattype = 3;
        }

        if ((whattype==1 || whattype==2 || whattype==3)&& s1[i+1] == '-'  && s1[i] < s1[i+2]){
            for (j=i+c, len = s1[i+2]-s1[i] + 1; j-i-c < len ; j++ ){
                
                s2[j] = s1[i]+(j-i-c);
               
            }
        }
        c +=len;
        i += 3; 
          
        if (s1[i] == '\0'){
            s2[j] = s1[i];  
        }
        
    }

}

