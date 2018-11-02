#ifndef PROJECTEULER_FRACTIONS_H
#define PROJECTEULER_FRACTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "digits.h"
#include "errormessages.h"
#include "numbers.h"

typedef struct Fraction Fraction;

Fraction * createFraction(int numerator, int denominator);
int getNumerator(Fraction *f);
int getDenominator(Fraction *f);

bool curiousFraction(Fraction *f);
bool identicalFractions(Fraction *a, Fraction *b);
bool equalFractions(Fraction *a, Fraction *b);
bool negativeFraction(Fraction *f);

Fraction * simplifyIncorrectly(Fraction *f);
Fraction * simplifyFraction(Fraction *f);
Fraction * normalizeFraction(Fraction *f);

Fraction * multiplyFractions(Fraction *a, Fraction *b);

#endif //PROJECTEULER_FRACTIONS_H
