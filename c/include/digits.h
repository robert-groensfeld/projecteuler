#ifndef PROJECTEULER_DIGITS_H
#define PROJECTEULER_DIGITS_H

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "numbers.h"
#include "errormessages.h"

#define lastPandigital 987654321

unsigned int getDigitCount(int number);
int getDigit(int number, unsigned int digitCount, unsigned int digitIndex);
unsigned int concat(unsigned int firstNumber, unsigned int secondNumber);
bool isPandigital(int number);
unsigned int previousPandigital();
bool isUnusualProduct(unsigned int multiplicand, unsigned int multiplier,
                      unsigned int product);
bool isCurious(unsigned int number);
bool isBase2Palindrome(unsigned int number);
bool isPalindrome(int number);
int removeDigit(int number, unsigned int digitIndex);
int rotateRight(int number);

#endif //PROJECTEULER_DIGITS_H