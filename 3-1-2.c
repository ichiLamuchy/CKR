/*
Exercise 3-1. 
Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside). 
Write a version with only one test inside the loop and measure the difference in run-time. 

This is original version - two condition in loop
*/

/* todo: check runtime */



#include <stdio.h> 

int binsearch1 (int x, int v[], int n);

int main(){
    int arr[] = { 2, 3, 4, 10, 40 }; 

    int n = sizeof(arr) / sizeof(arr[0]);           /* https://hackr.io/blog/binary-search-in-c */

    int x = 10; 

    int result = binsearch1(x, arr, n); 

    (result == -1) ? printf("The element is not present in array \n") 

                   : printf("The element is present at index %d \n", result); 

    return 0;
}

/*
binsearch:find x in v[O]<=v[1]<= ••• <=v[n-1]
*/ 

int binsearch1 (int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid =(low+high) / 2; 
        if (x < v[mid])
            high = mid - 1; 
        else if (x > v[mid])
            low =mid + 1;
        else /* foundmatch */
           return mid; 
    } 
    return -1; /*nomatch*/
}

/*
one condition within loop
*/

int binsearch2 (int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high && v[mid] != x) {
        mid =(low+high) / 2; 
        if (x < v[mid])
            high = mid - 1; 
        else /* (x > v[mid])*/
            low =mid + 1;
    }

    if(v[mid] == x){
        return mid; 
    }
    else
        return -1; /*nomatch*/   
    }
