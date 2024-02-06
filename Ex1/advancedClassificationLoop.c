#include "NumClass.h"
double power(double n, double y) {
    if(y == 0){
        return 1;
    }
    double res = 1;
    while (y > 0) {
        res *= n;
        y--;
    }
    return res;
}

int isArmstrong(int n){
    int numofdigits = 0;
    int temp = n;
    int x = n;
    int sum = 0;
    while(x > 0){
        numofdigits += 1;
        x /= 10;
    }
    while (temp > 0){
        int digit = temp % 10;
        sum += power(digit, numofdigits);
        temp /= 10;
    }
    return sum == n;
}

int isPalindrome(int n){
    int x = n;
    int c = 0;
    while(n > 0){
        int digit = n % 10;
        c = c * 10 + digit;
        n/=10;
    }
    return x == c;
}
