#include <gtest/gtest.h>

#if defined(__cplusplus)
extern "C" {
    #include "intlist.h"
}
#endif

TEST(isEmpty, EmptyOnCreation) {
    IntList *list = createIntList();
    EXPECT_TRUE(isEmptyIntList(list));
    freeIntList(list);
}

TEST(isEmpty, NotEmptyAfterAdd) {
    IntList *list = createIntList();
    addInt(list, 1);
    EXPECT_FALSE(isEmptyIntList(list));
    freeIntList(list);
}

TEST(getInt, ElementsAtRightPosition) {
    IntList *list = createIntList();
    addInt(list, 1);
    addInt(list, 2);
    EXPECT_EQ(getInt(list, 0), 1);
    EXPECT_EQ(getInt(list, 1), 2);
    freeIntList(list);
}

TEST(getSizeOfIntList, ZeroWhenEmpty) {
    IntList *list = createIntList();
    EXPECT_EQ(getSizeOfIntList(list), 0);
    freeIntList(list);
}

TEST(getSizeOfIntList, SizeGrowsWithAddedElements) {
    IntList *list = createIntList();
    for (int i = 0; i < 400; ++i) {
        EXPECT_EQ(getSizeOfIntList(list), i);
        addInt(list, i);
    }
    freeIntList(list);
}

TEST(getSizeOfIntList, SizeShrinksWithRemovedElements) {
    IntList *list = createIntList();
    int size = 200;
    for (int i = 0; i < size; ++i)
        addInt(list, i);
    removeLastInt(list);
    EXPECT_EQ(getSizeOfIntList(list), size - 1);
    int removed = size / 5;
    for (int i = removed; i > 0; --i)
        removeLastInt(list);
    EXPECT_EQ(getSizeOfIntList(list), size - 1 - removed);
    freeIntList(list);
}

TEST(containsInt, EmptyListContainsNothing) {
    IntList *list = createIntList();
    EXPECT_FALSE(containsInt(list, 0));
    EXPECT_FALSE(containsInt(list, 5));
    EXPECT_FALSE(containsInt(list, -200));
    freeIntList(list);
}

TEST(containsInt, ContainsOnlyAddedElements) {
    IntList *list = createIntList();
    addInt(list, -44);
    addInt(list, 56);
    addInt(list, 204);
    addInt(list, 77);

    EXPECT_TRUE(containsInt(list, -44));
    EXPECT_TRUE(containsInt(list, 204));
    EXPECT_TRUE(containsInt(list, 77));
    EXPECT_TRUE(containsInt(list, 56));

    EXPECT_FALSE(containsInt(list, 1));
    EXPECT_FALSE(containsInt(list, 2));
    EXPECT_FALSE(containsInt(list, 109));

    freeIntList(list);
}

TEST(getIntSum, SumAfterVariousAdditions) {
    IntList *list = createIntList();
    EXPECT_EQ(getIntSum(list), 0);
    addInt(list, 5);
    EXPECT_EQ(getIntSum(list), 5);
    addInt(list, 7);
    EXPECT_EQ(getIntSum(list), 12);
    addInt(list, -11);
    EXPECT_EQ(getIntSum(list), 1);
    addInt(list, 3);
    EXPECT_EQ(getIntSum(list), 4);

    freeIntList(list);
}