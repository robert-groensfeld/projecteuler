#include <gtest/gtest.h>

#if defined(__cplusplus)
extern "C" {
    #include "numbers.h"
}
#endif

TEST(greatestCommonDivisor, PositiveNumbers) {
    EXPECT_EQ(greatestCommonDivisor(13, 39), 13);
    EXPECT_EQ(greatestCommonDivisor(18, 45), 9);
    EXPECT_EQ(greatestCommonDivisor(17, 57), 1);
}

TEST(greatestCommonDivisor, Zero) {
    EXPECT_EQ(greatestCommonDivisor(2, 0), 2);
    EXPECT_EQ(greatestCommonDivisor(0, 14), 14);
    EXPECT_EQ(greatestCommonDivisor(-5, 0), 5);
    EXPECT_EQ(greatestCommonDivisor(0, -22), 22);
}

TEST(greatestCommonDivisor, NegativeNumbers) {
    EXPECT_EQ(greatestCommonDivisor(-10, 15), 5);
    EXPECT_EQ(greatestCommonDivisor(21, -14), 7);
    EXPECT_EQ(greatestCommonDivisor(-99, -66), 33);
}

TEST(factorial, ZeroToNine) {
    int results[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    for (unsigned int i  = 0; i < 10; ++i) {
        EXPECT_EQ(factorial(i), results[i]);
    }
}