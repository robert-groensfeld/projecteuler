#include "fractions.h"

struct Fraction {
    int numerator;
    int denominator;
};

Fraction * createFraction(int numerator, int denominator) {
    if (denominator == 0) {
        fprintf(stderr, "%s", INVALID_FRACTION_ERR);
        exit(EXIT_FAILURE);
    } else {
        Fraction *f = malloc(sizeof(*f));
        f->numerator = numerator;
        f->denominator = denominator;
        return f;
    }
}

int getNumerator(Fraction *f) {
    return f->numerator;
}

int getDenominator(Fraction *f) {
    return f->denominator;
}

bool curiousFraction(Fraction *f) {
    Fraction *correct = simplifyFraction(f);
    Fraction *incorrect = simplifyIncorrectly(f);

    bool simplifiable = ! identicalFractions(correct, f);
    bool incorrectlySimplifiable = ! identicalFractions(incorrect, f);

    bool curious;
    if (simplifiable && incorrectlySimplifiable)
        curious = equalFractions(correct, incorrect);
    else
        curious = false;

    free(correct);
    free(incorrect);
    return curious;
}

Fraction *simplifyIncorrectly(Fraction *f) {
    Fraction *simplified = createFraction(f->numerator, f->denominator);

    unsigned int numeratorCount = getDigitCount(f->numerator);
    unsigned int denominatorCount = getDigitCount(f->denominator);

    int i, j;
    for (i = 0; i < numeratorCount && numeratorCount > 1; ++i) {
        int numeratorDigit = getDigit(simplified->numerator, numeratorCount, (unsigned) i);

        for (j = 0; j < denominatorCount && denominatorCount > 1; ++j) {
            int denominatorDigit = getDigit(simplified->denominator, denominatorCount, (unsigned) j);

            if (numeratorDigit == denominatorDigit) {
                int newNumerator = removeDigit(simplified->numerator, (unsigned) i);
                int newDenominator = removeDigit(simplified->denominator, (unsigned) j);

                if(newDenominator != 0) {
                    --numeratorCount;
                    --denominatorCount;
                    --i;

                    simplified->numerator = newNumerator;
                    simplified->denominator = newDenominator;
                }

                // Only cancel one digit in the denominator.
                break;
            }
        }
    }

    return simplified;
}

Fraction *simplifyFraction(Fraction *f) {
    if (f->numerator == 0) {
        return createFraction(0, f->denominator);
    } else {
        int factor = greatestCommonDivisor(f->numerator, f->denominator);
        return createFraction(f->numerator / factor, f->denominator / factor);
    }
}

bool identicalFractions(Fraction *a, Fraction *b) {
    return a->numerator == b->numerator && a->denominator == b->denominator;
}

bool equalFractions(Fraction *a, Fraction *b) {
    bool bothZero = a->numerator == 0 && b->numerator == 0;
    if (bothZero) {
        return true;
    } else {
        Fraction *normalizedA = normalizeFraction(a);
        Fraction *normalizedB = normalizeFraction(b);
        bool equal = identicalFractions(normalizedA, normalizedB);
        free(normalizedA);
        free(normalizedB);
        return equal;
    }
}

bool negativeFraction(Fraction *f) {
    bool numNegative = f->numerator < 0;
    bool denomNegative = f->denominator < 0;
    bool bothNegative = numNegative && denomNegative;
    return (numNegative | denomNegative) && !bothNegative;
}

Fraction * normalizeFraction(Fraction *f) {
    int numerator = negativeFraction(f) ? -1 * abs(f->numerator) : f->numerator;
    int denominator = abs(f->denominator);

    Fraction *g = createFraction(numerator, denominator);
    Fraction *simplified = simplifyFraction(g);
    free(g);
    return simplified;
}

Fraction * multiplyFractions(Fraction *a, Fraction *b) {
    if (a->numerator == 0) {
        return createFraction(0, a->denominator);
    } else {
        int numerator = a->numerator * b->numerator;
        int denominator = a->denominator * b->denominator;
        return createFraction(numerator, denominator);
    }
}