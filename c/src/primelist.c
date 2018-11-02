#include "primelist.h"

struct PrimeList {
    unsigned int limit;
    bool *prime;
    unsigned int *primes;
    unsigned int count;
};

PrimeList *createPrimeList(unsigned int limit) {
    if (limit < 2) {
        fprintf(stderr, "%s", NO_PRIMES_BELOW_TWO_ERR);
        exit(EXIT_FAILURE);
    }
    
    PrimeList *l = (PrimeList *) malloc(sizeof(*l));
    l->limit = limit;

    bool *prime = (bool *) calloc(sizeof(unsigned int), limit + 1);

    unsigned const int firstPrime = 2;
    for (size_t number = 0; number < firstPrime; ++number)
        prime[number] = false;
    for(size_t number = firstPrime; number <= limit; ++number)
        prime[number] = true;

    size_t nextPrime = firstPrime;
    while (nextPrime * nextPrime <= limit) {
        for (size_t number = nextPrime * 2; number <= limit; number += nextPrime)
            prime[number] = false;

        do {
            ++nextPrime;
        } while (!prime[nextPrime]);
    }

    l->prime = prime;

    unsigned int *primes = (unsigned int *) calloc(limit, sizeof(*primes));
    unsigned int i = 0;
    for (size_t number = 0; number <= limit; ++number)
        if (prime[number])
            primes[i++] = number;
    l->count = i;
    l->primes = (unsigned int *) realloc(primes, l->count * sizeof(*primes));

    return l;
}

void freePrimeList(PrimeList *list) {
    free(list->prime);
    free(list);
}

bool containsPrime(PrimeList *list, unsigned int number) {
    if (number <= list->limit)
        return list->prime[number];
    else
        return false;
}

unsigned int getPrime(PrimeList *list, unsigned int index) {
    return list->primes[index];
}

unsigned int getPrimeCount(PrimeList *list) {
    return list->count;
}