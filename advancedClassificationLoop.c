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
    int tempx = x;
    int n = floor(log10(absAdvLoop(tempx)))+1;
    int tempn = n;
    int temp = 0;
    int temp2 = 0;
    for (int i=0; i<n/2;i++){
        tempn = floor(log10(absAdvLoop(tempx)))+1;
        temp = getNthDigitAdvLoop(tempx,tempn-1);
        temp2 = x%10;
        if (temp != temp2){
            return false;
        }
        tempx = tempx - pow(10,tempn);
        tempx /=10;
    }
    return true;
}