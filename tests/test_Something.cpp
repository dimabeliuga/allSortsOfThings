#include <gtest/gtest.h>
#include <iostream>
#include "Templates.h"

namespace {  // Добавляем анонимное пространство имен для тестов
    TEST(TemplatesTest, test_int_Template_Max){
        EXPECT_EQ(userImplementation::max(10, 20), 20);
    }
    TEST(TemplatesTest, test_double_and_float_Template_Max){
        EXPECT_DOUBLE_EQ(userImplementation::max(324.34, 564.123), 564.123); 
        EXPECT_FLOAT_EQ(userImplementation::max(324.34f, 564.123f), 564.123f);
    }
    TEST(TemplatesTest, test_string_Template_Max){
        std::string firstString{"Hello"};
        std::string secondString{"World"};
        const std::string& result = userImplementation::max(firstString, secondString);
        EXPECT_EQ(result, "World");
    }
    TEST(TemplatesTest, test_const_char_Template_Max){
        //* const char*
        const char* firstChar{"Hello"};
        const char* secondChar{"World"};
        const char* resultChar = userImplementation::max(firstChar, secondChar);
        EXPECT_STREQ(resultChar, "World");
    }
    TEST(UserClassCooperationWithMaxFunction, test_UserClass_Template_Max){
        UserClass firstUser{"John", 20};
        UserClass secondUser{"Doe", 30};
        const UserClass& resultUser = userImplementation::max(firstUser, secondUser);
        EXPECT_EQ(resultUser.getAge(), 30);
    }
    TEST(UserClassCooperationWithMaxFunction, test_UserClass_Template_Average){
        UserClass users[3] = {{ "John", 20 }, { "Doe", 30 }, { "Smith", 40 }};
        std::optional<double> result = userImplementation::average(users, 3);
        if(result.has_value()){
            EXPECT_DOUBLE_EQ(result.value(), 30.0);
        } else {
            ADD_FAILURE() << "The result is empty";
        }
    }
    TEST(UserContainerTest, test_UserContainer){
        UserContainer<int> container(6);
        container.fillWithIota(0);
        EXPECT_EQ(container.getValue(0), 0);
        EXPECT_EQ(container.getValue(1), 1);
        EXPECT_EQ(container.getValue(2), 2);
        container.setValue(5, 10);
        EXPECT_EQ(container.getValue(0), 10);

        try {
            container.setValue(45, 10);
            FAIL() << "Expected exception not thrown";
        } catch (const std::out_of_range& e) {
            SUCCEED();
        } catch (...) {
            FAIL() << "Unexpected exception type thrown";
        }
        EXPECT_EQ(container.getSize(), 6);
    }
    TEST(UserContainerTest, test_UserContainerImproved){
        userContainerImpoved<int, 6> container;
        container.fillWithIota(0);
        EXPECT_EQ(container.getValue(0), 0);
        EXPECT_EQ(container.getValue(1), 1);
        EXPECT_EQ(container.getValue(2), 2);
        container.setValue(5, 10);
        EXPECT_EQ(container.getValue(0), 10);
        EXPECT_EQ(container.getSize(), 6);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}