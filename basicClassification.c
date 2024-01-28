//
// Created by wasim on 1/21/2024.
//
#include"NumClass.h"
int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}
int factorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    return factorial(n -1) * n;
}
int isStrong(int n){
    int x = n;
    int sum = 0;
    while(x > 0){
        int digit = x % 10;
        sum += factorial(digit);
        x/=10;
    }
    return sum == n;
}
