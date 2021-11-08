#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define true 1
#define false 0

int abs(int x){
    if (x<0)
        return -1*x;
    return x;
}

int factorial(int x){
    if (x==0)
        return 1;
    int ans = 1;
    for (int i = 1; i <= x; i++){
        ans *= i;
    }
    return ans;
}

/*Strong number is a special number whose sum of the factorial of digits is equal to the original number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int x){ //just like in armstrong in loop but with factorial function?
    int n = floor(log10(abs(x)))+1;
    int sum = 0;
    int temp = x;
    int temp2 = 0;
    for (int i = 0; i < n; i++){
        temp2 = temp%10;
        sum = sum + factorial(temp2);
        temp /= 10;
    }
    if (sum == x)
        return true;
    return false;
}

/* will return if a number is prime*/
int isPrime(int x){
    //int n = floor(log10(abs(x)))+1;
    for (int i = 2; i <= sqrt(x); i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

