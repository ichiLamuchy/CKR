/*
Exercise 3-1. 
Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside). 
Write a version with only one test inside the loop and measure the difference in run-time. 

This is alt version, function call itself 
*/

/* todo: time ./a.out to check runtime  */


#include <stdio.h> 

int binsearch2(int x, int arr[], int n, int l);

int main(){
    int arr[] = { 2, 3, 4, 10, 40 }; 

    int n = sizeof(arr) / sizeof(arr[0]);           /* https://hackr.io/blog/binary-search-in-c */
    int x = 10; 
    int result = binsearch2(x, arr, n, 0); 

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
binsearch: this function calling themselves, not using loop

Param: 
int n will be highest index number on arr[]
int l will be lowest index number on arr[]
int x is the one serch

retun index of the array
*/ 

int binsearch2(int x, int arr[], int n, int l)
{
    int mid = (n + l) /2;

    if (n >= l){
        if (arr[mid] < x){
            return binsearch2 (x, arr, n, mid+1);
        }
        else if (arr[mid] > x){
            return binsearch2 (x, arr, mid-1, l);
        }
        else if (arr[mid] == x) 
            return mid;
    }
    return -1;  /* error if the input was co */

}

