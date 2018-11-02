#include <primelist.h>
#include "digits.h"

bool circularPrime(unsigned int number, PrimeList *primes);

int main(int argc, char *argv[]) {
    unsigned int count = 0;
    unsigned const int limit = 1000000;
    PrimeList *primes = createPrimeList(limit - 1);
    const unsigned int size = getPrimeCount(primes);
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int prime = getPrime(primes, i);
        if (circularPrime(prime, primes))
            count = count + 1;
    }
    printf("\nNumber of circular primes below %i: %i\n", limit, count);

    freePrimeList(primes);
    return 0;
}

bool circularPrime(unsigned int number, PrimeList *primes) {
    const unsigned int count = getDigitCount(number);
    unsigned int rotated = number;
    for (unsigned int i = 1; i < count; ++i) {
        rotated = (unsigned int) rotateRight((int) rotated);
        bool numberContainsZero = getDigitCount(rotated) < getDigitCount(number);
        if (!containsPrime(primes, rotated) || numberContainsZero)
            return false;
    }
    return true;
}