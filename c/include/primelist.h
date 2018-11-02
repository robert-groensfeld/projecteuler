#ifndef PROJECTEULER_PRIMELIST_H
#define PROJECTEULER_PRIMELIST_H

#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "errormessages.h"

typedef struct PrimeList PrimeList;

PrimeList *createPrimeList(unsigned int limit);
void freePrimeList(PrimeList *list);
bool containsPrime(PrimeList *list, unsigned int number);
unsigned int getPrime(PrimeList *list, unsigned int index);
unsigned int getPrimeCount(PrimeList *list);

#endif //PROJECTEULER_PRIMELIST_H
