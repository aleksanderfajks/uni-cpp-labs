#include "gtest/gtest.h"
#include "fibonacci.h"

TEST(fibonacciTest, differentInputs) {
    EXPECT_EQ(fibonacci(0), 0);
    EXPECT_EQ(fibonacci(1), 1);
    EXPECT_EQ(fibonacci(2), 1);
    EXPECT_EQ(fibonacci(3), 2);
    EXPECT_EQ(fibonacci(4), 3);
    EXPECT_EQ(fibonacci(5), 5);
    EXPECT_EQ(fibonacci(6), 8);
    EXPECT_EQ(fibonacci(7), 13);
    EXPECT_EQ(fibonacci(8), 21);
    EXPECT_EQ(fibonacci(9), 34);
    EXPECT_EQ(fibonacci(10), 55);
}