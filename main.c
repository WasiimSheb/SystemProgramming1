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
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("the Palindrome numbers are: ");
    for(int i = var1; i<= var2; i++){
        if (isPalindrome(i) == 1){
            printf(" %d",i);
        }
    }
    printf("\n");

    printf("the prime numbers are: ");
    for(int i = var1; i<= var2; i++) {
        if (isPrime(i) == 1) {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("the Strong numbers are: ");
    for(int i = var1; i<= var2; i++) {
        if (isStrong(i) == 1) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}
// #include <stdio.h>
// #include "NumClass.h"

// int main() {
// 	int num1,num2;
// 	int i;

// 	scanf("%d%d",&num1,&num2);

// 	printf("The Armstrong numbers are:");
// 	for (i = num1; i <= num2; i++) {
// 		if (isArmstrong(i)) printf(" %d",i);
// 	}
// 	printf("\nThe Palindromes are:");
// 	for (i = num1; i <= num2; i++) {
// 		if (isPalindrome(i)) printf(" %d",i);
// 	}
// 	printf("\nThe Prime numbers are:");
// 	for (i = num1; i <= num2; i++) {
// 		if (isPrime(i)) printf(" %d",i);
// 	}
// 	printf("\nThe Strong numbers are:");
// 	for (i = num1; i <= num2; i++) {
// 		if (isStrong(i)) printf(" %d",i);
// 	}
// 	printf("\n");

	return 0;
}
