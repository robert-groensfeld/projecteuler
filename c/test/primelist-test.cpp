#include <gtest/gtest.h>

#if defined(__cplusplus)
extern "C" {
    #include "primelist.h"
}
#endif

TEST(createPrimeList, LimitBelowTwo) {
    EXPECT_EXIT(createPrimeList(0),
                testing::ExitedWithCode(EXIT_FAILURE),
                NO_PRIMES_BELOW_TWO_ERR);
    EXPECT_EXIT(createPrimeList(1),
                testing::ExitedWithCode(EXIT_FAILURE),
                NO_PRIMES_BELOW_TWO_ERR);
}

TEST(containsPrime, FalseNegatives) {
    const unsigned int count = 10;
    unsigned int testPrimes[count] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const unsigned int limit = testPrimes[count - 1];
    PrimeList *generatedPrimes = createPrimeList(limit);
    for (int i = 0; i < count; ++i)
        EXPECT_TRUE(containsPrime(generatedPrimes, testPrimes[i]));
    freePrimeList(generatedPrimes);
}

TEST(containsPrime, FalsePositives) {
    const unsigned int count = 5;
    unsigned int nonPrimes[count] = {1, 4, 27, 39, 789412};
    PrimeList *primes = createPrimeList(100);
    for (int i = 0; i < count; ++i)
        EXPECT_FALSE(containsPrime(primes, nonPrimes[i]));
    freePrimeList(primes);
}

TEST(getPrime, CorrectOrder) {
    const unsigned int count = 10;
    unsigned int testPrimes[count] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const unsigned int limit = testPrimes[count - 1];
    PrimeList *generatedPrimes = createPrimeList(limit);
    for (int i = 0; i < count; ++i)
        EXPECT_EQ(getPrime(generatedPrimes, i), testPrimes[i]);
    freePrimeList(generatedPrimes);
}

TEST(getPrimeCount, RightCount) {
    PrimeList *primes = createPrimeList(2);
    EXPECT_EQ(getPrimeCount(primes), 1);
    freePrimeList(primes);

    primes = createPrimeList(29);
    EXPECT_EQ(getPrimeCount(primes), 10);
    freePrimeList(primes);
}