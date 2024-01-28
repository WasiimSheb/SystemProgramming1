
int power(int n, int y);

int countDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + countDigits(num / 10);
}

int isArmstrongRecursive(int num, int originalNum, int numDigits) {
    if (num == 0) {
        return (originalNum == 0);
    }

    int digit = num % 10;
    return (power(digit, numDigits) + isArmstrongRecursive(num / 10, originalNum, numDigits));
}

int isArmstrong2(int num) {
    int numDigits = countDigits(num);
    return isArmstrongRecursive(num, num, numDigits);
}
int isPalindromeRecursive(int num, int numDigits) {
    if (numDigits <= 1) {
        return 1;
    }

    int firstDigit = num / power(10, numDigits - 1);
    int lastDigit = num % 10;

    if (firstDigit != lastDigit) {
        return 0;
    }

    num = (num % power(10, numDigits - 1)) / 10;

    return isPalindromeRecursive(num, numDigits - 2);
}

int isPalindrome2(int num) {
    int numDigits = countDigits(num);
    return isPalindromeRecursive(num, numDigits);
}
