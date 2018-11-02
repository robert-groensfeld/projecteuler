#include "digits.h"

unsigned int getDigitCount(int number) {
    unsigned int count = 1;
    int rest = number / 10;
    while (rest != 0) {
        count = count + 1;
        rest = rest / 10;
    }
    return count;
}

int getDigit(int number, unsigned int digitCount, unsigned int digitIndex) {
    // Remove following digits and sign.
    int digit = abs((int) (number / pow(10, (digitCount - 1) - digitIndex)));
    // Remove preceding digits.
    return digit % 10;
}

unsigned int concat(unsigned int firstNumber, unsigned int secondNumber) {
    unsigned int count = getDigitCount(secondNumber);
    return firstNumber * (int) pow(10, count) + secondNumber;
}

bool isPandigital(int number) {
    unsigned int digitCount = getDigitCount(number);
    unsigned int digitTable = 0;

    for (unsigned int i = 0; i < digitCount; ++i) {
        int digit = getDigit(number, digitCount, i);
        unsigned int tableEntry = 1U << (digit - 1);
        digitTable = digitTable | tableEntry;
    }

    return digitTable == (pow(2, digitCount) - 1);
}

unsigned int previousPandigital() {
    static unsigned int prefix = 9876543;
    static unsigned int suffix = 21;

    return concat(prefix, suffix);
}

bool isUnusualProduct(unsigned int multiplicand,
                      unsigned int multiplier,
                      unsigned int product) {
    unsigned int concatenation = concat(multiplicand, multiplier);
    concatenation = concat(concatenation, product);
    int digitCount = getDigitCount(concatenation);
    return digitCount == 9 && isPandigital(concatenation);
}

bool isCurious(unsigned int number) {
    if (number == 1 || number == 2)
        return false;

    unsigned int factorialSum = 0;
    unsigned int digitCount = getDigitCount((int) number);

    unsigned int i;
    for (i = 0; i < digitCount; ++i) {
        int digit = getDigit(number, digitCount, i);
        unsigned int fac = factorial((unsigned int) digit);
        factorialSum = factorialSum + fac;
    }

    return factorialSum == number;
}

bool isBase2Palindrome(unsigned int number) {
    unsigned int copy = number;
    unsigned int reverse = 0;
    while (copy > 0) {
        reverse = (copy % 2 == 1) ? reverse << 1 | 1U : reverse << 1;
        copy >>= 1;
    }
    return number == reverse;
}

bool isPalindrome(int number) {
    unsigned int count = getDigitCount(number);
    for (unsigned int i = 0; i < (int) count / 2; ++i) {
        int left = getDigit(number, count, i);
        int right = getDigit(number, count, count - 1 - i);
        if (left != right)
            return false;
    }
    return true;
}

int removeDigit(int number, unsigned int digitIndex) {
    if (abs(number) < 10) {
        fprintf(stderr, "%s", INVALID_DIGIT_REMOVAL_ERR);
        exit(EXIT_FAILURE);
    } else {
        int absolute = abs(number);
        unsigned int digitCount = getDigitCount(number);

        // Get preceding digits.
        int preceding = absolute / (int) pow(10, digitCount - digitIndex);
        // Get following digits.
        int following = absolute % (int) pow(10, digitCount - digitIndex - 1);

        int absoluteResult = preceding * (int) pow(10, digitCount - digitIndex - 1) + following;

        if (number < 0)
            return -1 * absoluteResult;
        else
            return absoluteResult;
    }
}

int rotateRight(int number) {
    int digitCount = getDigitCount(number);
    int lastDigit = number % 10;
    int firstDigits = number / 10;
    return (int) pow(10, digitCount - 1) * lastDigit + firstDigits;
}