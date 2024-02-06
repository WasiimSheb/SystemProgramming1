// #include"NumClass.h"
// int power2(int n, int y) {
//     int  res = 1;
//     while (y > 0) {
//         res *= n;
//         y--;
//     }
//     return res;
// }
// int countDigits(int num) {
//     if (num == 0) {
//         return 0;
//     }
//     return 1 + countDigits(num / 10);
// }

// int isArmstrongRecursive(int num, int originalNum, int numDigits) {
//     if (num == 0) {
//         return (originalNum == 0);
//     }

//     int digit = num % 10;
//     return (power2(digit, numDigits) + isArmstrongRecursive(num / 10, originalNum, numDigits));
// }

// int isArmstrong(int num) {
//     int numDigits = countDigits(num);
//     return isArmstrongRecursive(num, num, numDigits);
// }
// int isPalindromeRecursive(int num, int numDigits) {
//     if (numDigits <= 1) {
//         return 1;
//     }

//     int firstDigit = num / power2(10, numDigits - 1);
//     int lastDigit = num % 10;

//     if (firstDigit != lastDigit) {
//         return 0;
//     }

//     num = (num % power2(10, numDigits - 1)) / 10;

//     return isPalindromeRecursive(num, numDigits - 2);
// }

// int isPalindrome(int num) {
//     int numDigits = countDigits(num);
//     return isPalindromeRecursive(num, numDigits);
// }
#include "NumClass.h"

// Recursive function to calculate the power of a digit
double pow2(double n,double exponent){
    if(exponent == 0){return 1;}
    double result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= n;
    }
    return result;
}

// Recursive function to calculate the sum of digits raised to the power of the number of digits
int armstrongRecursive(int num, int d) {
    if (num == 0) {
        return 0;
    }
    return armstrongRecursive(num / 10, d) + pow2(num % 10, d);
}

// Recursive function to count the number of digits
int countDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + countDigits(num / 10);
}

// Recursive function to reverse the digits of a number
int palindromeRecursive(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
  return palindromeRecursive(num / 10, (reversed * 10) + (num % 10));
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int d = countDigits(num);

    if (num == armstrongRecursive(num, d)) {
        return 1;
    }

    return 0;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    if (num == palindromeRecursive(num, 0)) {
        return 1;
    }

   return 0;
}
