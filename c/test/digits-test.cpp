#include <gtest/gtest.h>
#include "errormessages.h"

#if defined(__cplusplus)
extern "C" {
    #include "digits.h"
}
#endif

TEST(getDigitCount, NegativeNumbers) {
    EXPECT_EQ(getDigitCount(-1), 1);
    EXPECT_EQ(getDigitCount(-439), 3);
    EXPECT_EQ(getDigitCount(-0), 1);
}

TEST(getDigitCount, PositiveNumbers) {
    EXPECT_EQ(getDigitCount(1), 1);
    EXPECT_EQ(getDigitCount(5679), 4);
    EXPECT_EQ(getDigitCount(0), 1);
}

TEST(getDigit, PositiveNumbers) {
    EXPECT_EQ(getDigit(24, 2, 0), 2);
    EXPECT_EQ(getDigit(724, 3, 1), 2);
    EXPECT_EQ(getDigit(7246, 4, 3), 6);
    EXPECT_EQ(getDigit(0, 1, 0), 0);
}

TEST(getDigit, NegativeNumbers) {
    EXPECT_EQ(getDigit(-24, 2, 0), 2);
    EXPECT_EQ(getDigit(-724, 3, 1), 2);
    EXPECT_EQ(getDigit(-7246, 4, 3), 6);
    EXPECT_EQ(getDigit(-0, 1, 0), 0);
}

TEST(concat, Zero) {
    EXPECT_EQ(concat(0, 0), 0);
    EXPECT_EQ(concat(0, 30), 30);
    EXPECT_EQ(concat(30, 0), 300);
    EXPECT_EQ(concat(1020, 0), 10200);
}

TEST(concat, ArbitraryValues) {
    EXPECT_EQ(concat(7, 2), 72);
    EXPECT_EQ(concat(422, 24777), 42224777);
    EXPECT_EQ(concat(13, 37), concat(133, 7));
}

TEST(isPandigital, NonPandigitalNumbers) {
    EXPECT_FALSE(isPandigital(2));
    EXPECT_FALSE(isPandigital(11));
    EXPECT_FALSE(isPandigital(0));
    EXPECT_FALSE(isPandigital(-0));
    EXPECT_FALSE(isPandigital(-7));
    EXPECT_FALSE(isPandigital(-22));
}

TEST(isPandigital, PandigitalNumbers) {
    EXPECT_TRUE(isPandigital(1));
    EXPECT_TRUE(isPandigital(-1));
    EXPECT_TRUE(isPandigital(312));
    EXPECT_TRUE(isPandigital(-4132));
    EXPECT_TRUE(isPandigital(7523641));
}

TEST(isUnusualProduct, UnusualProduct) {
    EXPECT_TRUE(isUnusualProduct(39, 186, 7254));
}

TEST(isUnusualProduct, UsualProducts) {
    EXPECT_FALSE(isUnusualProduct(12, 12, 12 * 12));
    EXPECT_FALSE(isUnusualProduct(12, 34, 408));
    EXPECT_FALSE(isUnusualProduct(123, 78, 9594));
    EXPECT_FALSE(isUnusualProduct(3, 582, 1746));
}

TEST(removeDigit, PositiveNumbers) {
    EXPECT_EQ(removeDigit(1234, 3), 123);
    EXPECT_EQ(removeDigit(2754, 0), 754);
    EXPECT_EQ(removeDigit(7531, 2), 751);
}

TEST(removeDigit, NegativeNumbers) {
    EXPECT_EQ(removeDigit(-1234, 3), -123);
    EXPECT_EQ(removeDigit(-2754, 0), -754);
    EXPECT_EQ(removeDigit(-7531, 2), -751);
}

TEST(removeDigit, ExitOnNumberWithSingleDigit) {
    EXPECT_EXIT(removeDigit(9, 1),
                testing::ExitedWithCode(EXIT_FAILURE),
                INVALID_DIGIT_REMOVAL_ERR);
}

TEST(isCurious, FalsePositives) {
    EXPECT_FALSE(isCurious(10));
    EXPECT_FALSE(isCurious(146));
    EXPECT_FALSE(isCurious(1));
    EXPECT_FALSE(isCurious(2));
}

TEST(isCurious, FalseNegative) {
    EXPECT_TRUE(isCurious(145));
}

TEST(rotateRight, NegativeNumbers) {
    EXPECT_EQ(rotateRight(-1230), -123);
    EXPECT_EQ(rotateRight(-1), -1);
    EXPECT_EQ(rotateRight(-231), -123);
    EXPECT_EQ(rotateRight(-11), -11);
}

TEST(rotateRight, PositiveNumbers) {
    EXPECT_EQ(rotateRight(1230), 123);
    EXPECT_EQ(rotateRight(1), 1);
    EXPECT_EQ(rotateRight(231), 123);
    EXPECT_EQ(rotateRight(11), 11);
}

TEST(rotateRight, Zero) {
    EXPECT_EQ(rotateRight(0), 0);
}

TEST(isBase2Palindrome, FalsePositives) {
    EXPECT_FALSE(isBase2Palindrome(2));     // 10
    EXPECT_FALSE(isBase2Palindrome(6));     // 110
    EXPECT_FALSE(isBase2Palindrome(11));    // 1011
}

TEST(isBase2Palindrome, FalseNegatives) {
    EXPECT_TRUE(isBase2Palindrome(0));      // 0
    EXPECT_TRUE(isBase2Palindrome(1));      // 1
    EXPECT_TRUE(isBase2Palindrome(9));      // 1001
    EXPECT_TRUE(isBase2Palindrome(15));     // 1111
    EXPECT_TRUE(isBase2Palindrome(21));     // 10101
}

TEST(isPalindrome, FalsePositives) {
    EXPECT_FALSE(isPalindrome(12));
    EXPECT_FALSE(isPalindrome(-145641));
    EXPECT_FALSE(isPalindrome(1144));
    EXPECT_FALSE(isPalindrome(-11522));
}

TEST(isPalindrome, FalseNegatives) {
    for (int i = -9; i <= 9; ++i)
        EXPECT_TRUE(isPalindrome(i));
    EXPECT_TRUE(isPalindrome(4444));
    EXPECT_TRUE(isPalindrome(41414));
    EXPECT_TRUE(isPalindrome(-2267622));
}