#include <stdio.h>
#include "NumClass.h"
int main() {
    int var1;
    int var2;
    scanf("%d", &var1);
    scanf("%d", &var2);
    printf("the Armstrong numbers are: ");
    for(int i = var1; i<= var2; i++) {
        if (isArmstrong(i) == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("the Palindrome numbers are: ");
    for(int i = var1; i<= var2; i++){
        if (ispalindrome(i) == 1){
            printf("%d ",i);
        }
    }
    printf("\n");

    printf("the prime numbers are: ");
    for(int i = var1; i<= var2; i++) {
        if (isPrime(i) == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    printf("the Strong numbers are: ");
    for(int i = var1; i<= var2; i++) {
        if (isStrong(i) == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
