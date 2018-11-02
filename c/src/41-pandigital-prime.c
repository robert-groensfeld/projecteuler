#include <stdio.h>
#include <primelist.h>
#include <digits.h>

int main() {
    const unsigned int largestPandigital = 7654321;
    const unsigned int knownPandigitalPrime = 2143;
    PrimeList *l = createPrimeList(largestPandigital);

    unsigned int largestPandigitalPrime = knownPandigitalPrime;
    for (unsigned int i = largestPandigital; i > knownPandigitalPrime; --i)
        if (isPandigital((int) i) && containsPrime(l, i)) {
            largestPandigitalPrime = i;
            break;
        }

    freePrimeList(l);
    printf("Largest pandigital prime: %u\n", largestPandigitalPrime);
    return 0;
}