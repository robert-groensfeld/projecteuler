#include <digits.h>
#include <primelist.h>

int main(int argc, char* argv[]) {
    unsigned int limit = 1000000;
    PrimeList *primes = createPrimeList(limit - 1);
    unsigned int primeCount = 0;
    int sum = 0;

    unsigned int number = 11;
    while (primeCount < 11) {
        unsigned int digitCount = getDigitCount(number);
        unsigned int truncLeft = number;
        unsigned int truncRight = number;

        unsigned int truncDigitCount = digitCount;
        while (truncDigitCount > 1) {
            if (containsPrime(primes, truncLeft) && containsPrime(primes, truncRight)) {
                truncLeft = (unsigned int) removeDigit((int) truncLeft, 0);
                truncRight = (unsigned int) removeDigit((int) truncRight, truncDigitCount - 1);
                truncDigitCount = truncDigitCount - 1;
            } else {
                break;
            }
        }

        if (truncDigitCount == 1 && containsPrime(primes, truncLeft) && containsPrime(primes, truncRight)) {
            printf("%i ", number);
            sum += number;
            primeCount = primeCount + 1;
        }

        number = number + 1;
    }

    printf("\nSum: %i", sum);
    freePrimeList(primes);
    return 0;
}
