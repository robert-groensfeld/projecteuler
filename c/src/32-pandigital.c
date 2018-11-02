#include <stdio.h>
#include "digits.h"
#include "intlist.h"

int main(int argc, char* argv[]) {
    IntList *products = createIntList();
    const int maxProduct = 9876;
    const int maxMultiplicand = 98;

    for (int multiplicand = 1; multiplicand < maxMultiplicand; ++multiplicand) {
        const int maxMultiplier = maxProduct / multiplicand;
        const int minMultiplier = maxProduct / maxMultiplicand;

        for (int multiplier = minMultiplier; multiplier < maxMultiplier; ++multiplier) {
            int product = multiplicand * multiplier;

            if (isUnusualProduct(multiplicand, multiplier, product)) {
                char format[] = "%2d * %-5d = %4d\n";
                if (!containsInt(products, product)) {
                    addInt(products, product);
                    printf(format, multiplicand, multiplier, product);
                } else {
                    fprintf(stderr, format, multiplicand, multiplier, product);
                }
            }
        }
    }

    printf("\nSum: %12d\n", getIntSum(products));

    free(products);
    return 0;
}