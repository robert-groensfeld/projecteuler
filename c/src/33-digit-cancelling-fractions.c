#include "fractions.h"

static bool trivial(Fraction *f) {
    return getNumerator(f) % 10 == 0 && getDenominator(f) % 10 == 0;
}

int main(int argc, char *argv[]) {
    int i, j;
    Fraction *product = createFraction(1, 1);

    printf("The four non-trivial curious fractions:\n\n");
    for (i = 10; i <= 98; ++i) {
        for(j = i + 1; j <= 99; ++j) {
            Fraction *f = createFraction(i, j);
            if (!trivial(f) && curiousFraction(f)) {
                Fraction *temp = multiplyFractions(product, f);
                free(product);
                product = temp;
                printf("%i/%i\t", getNumerator(f), getDenominator(f));
            }
            free(f);
        }
    }
    Fraction *simplifiedProduct = simplifyFraction(product);
    free(product);
    printf("\n\nThe product of these fraction in its lowest common terms: %i/%i\n",
           getNumerator(simplifiedProduct),
           getDenominator(simplifiedProduct));
}