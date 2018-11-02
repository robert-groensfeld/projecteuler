#include <gtest/gtest.h>

#if defined(__cplusplus)
extern "C" {
    #include "fractions.h"
}
#endif

TEST(createFraction, RightNumerator) {
    Fraction *f = createFraction(3, 2);
    EXPECT_EQ(getNumerator(f), 3);
    free(f);
    f = createFraction(-1, 4);
    EXPECT_EQ(getNumerator(f), -1);
    free(f);
}

TEST(createFraction, RightDenominator) {
    Fraction *f = createFraction(2, 4);
    EXPECT_EQ(getDenominator(f), 4);
    free(f);
    f = createFraction(-2, -2);
    EXPECT_EQ(getDenominator(f), -2);
    free(f);
}

TEST(createFraction, DivisionByZero) {
    EXPECT_EXIT(createFraction(4, 0),
                testing::ExitedWithCode(EXIT_FAILURE),
                INVALID_FRACTION_ERR);
}

TEST(curiousFraction, CuriousFractions) {
    Fraction *f = createFraction(49, 98);
    EXPECT_TRUE(curiousFraction(f));
    free(f);
    f = createFraction(30, 50);
    EXPECT_TRUE(curiousFraction(f));
    free(f);
    f = createFraction(-49, 98);
    EXPECT_TRUE(curiousFraction(f));
    free(f);
}

TEST(curiousFraction, OrdinaryFractions) {
    Fraction *f = createFraction(3, 4);
    EXPECT_FALSE(curiousFraction(f));
    free(f);
    f = createFraction(24, 48);
    EXPECT_FALSE(curiousFraction(f));
    free(f);
    f = createFraction(10, 22);
    EXPECT_FALSE(curiousFraction(f));
    free(f);
}

TEST(simplifyFraction, Simplifiable) {
    Fraction *raw = createFraction(10, 22);
    Fraction *simplified = createFraction(5, 11);
    EXPECT_TRUE(identicalFractions(simplifyFraction(raw), simplified));
    free(raw);
    free(simplified);
    raw = createFraction(-13, 39);
    simplified = createFraction(-1, 3);
    EXPECT_TRUE(identicalFractions(simplifyFraction(raw), simplified));
    free(raw);
    free(simplified);
}

TEST(simplifyFraction, NonSimplifiable) {
    Fraction *a = createFraction(4, 9);
    EXPECT_TRUE(identicalFractions(simplifyFraction(a), a));
    free(a);
    a = createFraction(12, 17);
    EXPECT_TRUE(identicalFractions(simplifyFraction(a), a));
    free(a);
}

TEST(simplifyFraction, Zero) {
    Fraction *f = createFraction(0, -2);
    Fraction *g = createFraction(0, 54);
    EXPECT_TRUE(identicalFractions(simplifyFraction(f), f));
    EXPECT_TRUE(identicalFractions(simplifyFraction(g), g));
    free(f);
    free(g);
}

TEST(identicalFractions, FalsePositives) {
    Fraction *a = createFraction(2, 5);
    Fraction *b = createFraction(3, 7);
    EXPECT_FALSE(identicalFractions(a, b));
    free(a);
    free(b);
    a = createFraction(13, 14);
    b = createFraction(2, 3);
    EXPECT_FALSE(identicalFractions(a, b));
    free(a);
    free(b);
}

TEST(identicalFractions, FalseNegatives) {
    Fraction *a = createFraction(-3, 4);
    Fraction *b = createFraction(-3, 4);
    EXPECT_TRUE(identicalFractions(a, b));
    free(a);
    free(b);
    a = createFraction(124, 5634);
    b = createFraction(124, 5634);
    EXPECT_TRUE(identicalFractions(a, b));
    free(a);
    free(b);
}

TEST(simplifyIncorrectly, Simplifiable) {
    Fraction *beforeSimplification = createFraction(49, 98);
    Fraction *afterSimplification = simplifyIncorrectly(beforeSimplification);
    Fraction *testFraction = createFraction(4, 8);
    EXPECT_TRUE(identicalFractions(afterSimplification, testFraction));
    free(beforeSimplification);
    free(afterSimplification);
    free(testFraction);

    beforeSimplification = createFraction(112, 71);
    afterSimplification = simplifyIncorrectly(beforeSimplification);
    testFraction = createFraction(12, 7);
    EXPECT_TRUE(identicalFractions(afterSimplification, testFraction));
    free(beforeSimplification);
    free(afterSimplification);
    free(testFraction);

    beforeSimplification = createFraction(-1122, 52532);
    afterSimplification = simplifyIncorrectly(beforeSimplification);
    testFraction = createFraction(-11, 553);
    EXPECT_TRUE(identicalFractions(afterSimplification, testFraction));
    free(beforeSimplification);
    free(afterSimplification);
    free(testFraction);
}

TEST(simplifyIncorrectly, NonSimplifiable) {
    Fraction *beforeSimplification = createFraction(10, 22);
    Fraction *afterSimplification = simplifyIncorrectly(beforeSimplification);
    EXPECT_TRUE(identicalFractions(beforeSimplification, afterSimplification));
    free(beforeSimplification);
    free(afterSimplification);

    beforeSimplification = createFraction(13, -52);
    afterSimplification = simplifyIncorrectly(beforeSimplification);
    EXPECT_TRUE(identicalFractions(beforeSimplification, afterSimplification));
    free(beforeSimplification);
    free(afterSimplification);

    beforeSimplification = createFraction(12, 20);
    afterSimplification = simplifyIncorrectly(beforeSimplification);
    EXPECT_TRUE(identicalFractions(beforeSimplification, afterSimplification));
    free(beforeSimplification);
    free(afterSimplification);
}

TEST(equalFractions, OtherThanZero) {
    Fraction *a = createFraction(3, 4);
    Fraction *b = createFraction(9, 12);
    EXPECT_TRUE(equalFractions(a, b));
    free(a);
    free(b);

    a = createFraction(-3, 9);
    b = createFraction(3, -9);
    EXPECT_TRUE(equalFractions(a, b));
    free(a);
    free(b);
}

TEST(equalFractions, Zero) {
    Fraction *a = createFraction(0, -77);
    Fraction *b = createFraction(0, 64375);
    EXPECT_TRUE(equalFractions(a, b));
    free(a);
    free(b);
}

TEST(negativeFraction, FalsePositives) {
    Fraction *f = createFraction(22, 66);
    EXPECT_FALSE(negativeFraction(f));
    free(f);

    f = createFraction(0, 123);
    EXPECT_FALSE(negativeFraction(f));
    free(f);

    f = createFraction(-15, -30);
    EXPECT_FALSE(negativeFraction(f));
    free(f);
}

TEST(negativeFraction, FalseNegatives) {
    Fraction *f = createFraction(-22, 78);
    EXPECT_TRUE(negativeFraction(f));
    free(f);

    f = createFraction(16, -32);
    EXPECT_TRUE(negativeFraction(f));
    free(f);
}

TEST(normalizeFraction, Positive) {
    Fraction *f = createFraction(22, 88);
    Fraction *normalized = normalizeFraction(f);
    Fraction *test = createFraction(1, 4);
    EXPECT_TRUE(identicalFractions(normalized, test));
    free(f);
    free(normalized);
    free(test);
}

TEST(normalizeFraction, Negative) {
    Fraction *f = createFraction(-15, 18);
    Fraction *normalized = normalizeFraction(f);
    Fraction *test = createFraction(-5, 6);
    EXPECT_TRUE(identicalFractions(normalized, test));
    free(f);
    free(normalized);
    free(test);

    f = createFraction(14, -35);
    normalized = normalizeFraction(f);
    test = createFraction(-2, 5);
    EXPECT_TRUE(identicalFractions(normalized, test));
    free(f);
    free(normalized);
    free(test);
}

TEST(normalizeFraction, Zero) {
    Fraction *f = createFraction(0, -5);
    Fraction *normalized = normalizeFraction(f);
    Fraction *test = createFraction(0, 5);
    EXPECT_TRUE(identicalFractions(normalized, test));
    free(f);
    free(normalized);
    free(test);

    f = createFraction(0, 35);
    normalized = normalizeFraction(f);
    test = createFraction(0, 35);
    EXPECT_TRUE(identicalFractions(normalized, test));
    free(f);
    free(normalized);
    free(test);
}

TEST(multiplyFractions, Positive) {
    Fraction *a = createFraction(5, 7);
    Fraction *b = createFraction(3, 8);
    Fraction *product = multiplyFractions(a, b);
    Fraction *test = createFraction(15, 56);
    EXPECT_TRUE(identicalFractions(product, test));
    free(a);
    free(b);
    free(product);
    free(test);
}

TEST(multiplyFractions, Negative) {
    Fraction *a = createFraction(-7, 9);
    Fraction *b = createFraction(1, -2);
    Fraction *product = multiplyFractions(a, b);
    Fraction *test = createFraction(-7, -18);
    EXPECT_TRUE(identicalFractions(product, test));
    free(a);
    free(b);
    free(product);
    free(test);

    a = createFraction(7, -12);
    b = createFraction(-3, 2);
    product = multiplyFractions(a, b);
    test = createFraction(-21, -24);
    EXPECT_TRUE(identicalFractions(product, test));
    free(a);
    free(b);
    free(product);
    free(test);
}

TEST(multiplyFractions, Zero) {
    Fraction *a = createFraction(0, 124);
    Fraction *b = createFraction(44, 48);
    Fraction *product = multiplyFractions(a, b);
    Fraction *test = createFraction(0, 124);
    EXPECT_TRUE(identicalFractions(product, test));
    free(a);
    free(b);
    free(product);
    free(test);
}