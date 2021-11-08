#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define true 1
#define false 0

int absAdvLoop(int x){
    if (x<0)
        return -1*x;
    return x;
}

int getNthDigitAdvLoop(int x, int n){
    int temp = x;
    int r = temp / pow(10,n);
    r=r%10;
    return r;
}

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407
*/
int isArmstrong(int x){
    int n = floor(log10(absAdvLoop(x)))+1;
    int sum = 0;
    int temp = x;
    int temp2 = 0;
    for (int i = 0; i < n; i++){
        temp2 = temp%10;
        sum = sum + pow(temp2,n);
        temp /= 10;
    }
    if (sum == x){
        return true;
    }
    return false;
}
/* will return if a number is a palindrome */
int isPalindrome(int x){
    if (x<10)
        return 1;
    int tempx = x;
    int n = floor(log10(absAdvLoop(tempx)))+1;
    int reversed = 0;
    for (int i = 1; i<=n;i++){
        int temp = tempx%10;
        reversed += temp*pow(10,n-i);
        tempx /= 10;
    }
    return reversed==x;
}