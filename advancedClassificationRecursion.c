#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define true 1
#define false 0

int absAdvRec(int x){
    if (x<0)
        return -1*x;
    return x;
}

int getNthDigitAdvRec(int x, int n){
    int temp = x;
    int r = temp / pow(10,n);
    r=r%10;
    return r;
}

int isArmstrongRecursion(int x, int n){
    if(x==0){
        return x;
    }
    return pow(x%10,n)+isArmstrongRecursion(x/10,n);
}

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int x){
    int n = floor(log10(absAdvRec(x)))+1;
    int sum = isArmstrongRecursion(x,n);
    return x==sum;
}


/* will return if a number is a palindrome */
int isPalindrome(int x){
    if (x<10)
        return 1;
    int n = floor(log10(absAdvRec(x)))+1;
    int temp = getNthDigitAdvRec(x,n-1);
    int temp2 = x%10;
    if (temp != temp2)
        return false;
    x = x - pow(10,n);
    x /=10;
    
    return isPalindrome(x);
}