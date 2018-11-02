#include <stdio.h>
#include "digits.h"

int main(int argc, char **argv) {
    unsigned int maxProduct = 918273645;
    for (unsigned int rest = 1; rest <= 876; ++rest) {
        unsigned int number = concat(9, rest);
        unsigned int digits = getDigitCount(number);
        for (int multiplier = 2; digits < 9; ++multiplier) {
            unsigned int product = multiplier * number;
            number = concat(number, product);
            digits = getDigitCount(number);
        }
        if (isPandigital(number) && number > maxProduct)
            maxProduct = number;
    }
    printf("Largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer: %u", maxProduct);
    return 0;
}
