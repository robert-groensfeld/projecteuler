#include "numbers.h"

int greatestCommonDivisor(int a, int b) {
    // Euclid's algorithm.

    if (b == 0)
        return abs(a);

    int first = abs(a);
    int second = abs(b);
    int rest = first % second;

    while (rest != 0) {
        first = second;
        second = rest;
        rest = first % second;
    }

    return second;
}

unsigned int factorial(unsigned int number) {
    int factorial = 1;
    unsigned int i;
    for (i = 2; i <= number; ++i)
        factorial = factorial * i;
    return factorial;
}