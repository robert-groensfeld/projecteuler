#include <numbers.h>
#include <digits.h>

int main(int argc, char* argv[]) {
    const unsigned int maxFactorial = factorial(9);
    unsigned int sum = 0;

    // Adding a digit will multiply the number at least by factor 10.
    // The sum of digit factorials will increase by at most 9! when
    // we add a new digit to the number. We are done searching when
    // the number is so high that adding a digit will increase by more than 9!.
    for (unsigned int number = 10; number - (number / 10) <= maxFactorial; ++number) {
        if (isCurious(number)) {
            unsigned int digits = getDigitCount((int) number);
            for (unsigned int i = 0; i < digits - 1; ++i) {
                int digit = getDigit((int) number, digits, i);
                printf("%i! + ", digit);
            }
            int lastDigit = getDigit((int) number, digits, digits - 1);
            printf("%i! = %i\n", lastDigit, number);
            sum = sum + number;
        }
    }

    printf("Sum: %i", sum);

    return 0;
}