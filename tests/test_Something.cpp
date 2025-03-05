#include <gtest/gtest.h>
#include <iostream>

int add(int a, int b) {
    return a + b;
}

namespace {  // Добавляем анонимное пространство имен для тестов
    TEST(MathTest, AdditionTest) {
        EXPECT_EQ(add(2, 3), 5);
        EXPECT_EQ(add(-1, 1), 0);
        EXPECT_EQ(add(0, 0), 0);
    }

    TEST(ComparisonTest, EqualityTest) {
        int x = 5;
        int y = 5;
        EXPECT_EQ(x, y);
    }

    TEST(ComparisonTest, InequalityTest) {
        int x = 5;
        int y = 6;
        EXPECT_NE(x, y);
    }

    TEST(BooleanTest, TruthTest) {
        bool result = true;
        EXPECT_TRUE(result);
        EXPECT_FALSE(1 == 2);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}