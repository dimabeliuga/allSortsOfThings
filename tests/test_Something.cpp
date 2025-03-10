#include <gtest/gtest.h>
#include <iostream>
#include "Templates.h"
#include "C++11Features.h"
namespace Templates{  // Добавляем анонимное пространство имен для тестов
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
    }
    TEST(UserContainerTest, test_UserContainerImproved){
        userContainerImpoved<int, 6> container;
        container.fillWithIota(0);
        EXPECT_EQ(container.getValue(0), 0);
        EXPECT_EQ(container.getValue(1), 1);
        EXPECT_EQ(container.getValue(2), 2);
        container.setValue(5, 10);
        EXPECT_NE(container.getValue(0), 10);
        EXPECT_EQ(container.getSize(), 6);
    }
}

namespace C11Features{
    class StudentTest : public ::testing::Test {
        protected:
            Student student1;
            Student student2;
            Student student3;
        
            StudentTest() : 
                student1("Alice", 20, 3.8, 5),
                student2("Bob", 22, 3.5, 2),
                student3("Charlie", 19, 3.9, 8) 
            {}
        
            virtual ~StudentTest() {}
    };

    TEST_F(StudentTest, CalculateScoreTest) {
        EXPECT_NEAR(calculateScore(student1), 7.4, 0.01);
        EXPECT_NEAR(calculateScore(student2), 6.75, 0.01);
        EXPECT_NEAR(calculateScore(student3), 8.15, 0.01);
    }


    TEST(FilterAndSortStudentsTest, BasicTest) {
        std::vector<Student> students = {
            {"Alice", 20, 3.8, 5},
            {"Bob", 22, 3.5, 2},
            {"Charlie", 19, 3.9, 8},
            {"Diana", 21, 3.7, 4}
        };
        double threshold = 7.0;
    
        auto topStudents = filterStudents(students, threshold);
    
        EXPECT_EQ(topStudents.size(), 3);
        EXPECT_EQ(topStudents[0].getName(), "Charlie");
        EXPECT_EQ(topStudents[1].getName(), "Alice");
        EXPECT_EQ(topStudents[2].getName(), "Diana");
    }

    TEST(FilterAndSortStudentsTest, DifferentThresholdTest) {
        std::vector<Student> students = {
            {"Alice", 20, 3.8, 5},
            {"Bob", 22, 3.5, 2},
            {"Charlie", 19, 3.9, 8},
            {"Diana", 21, 3.7, 4}
        };
        double threshold = 4.0;
    
        auto topStudents = filterStudents(students, threshold);
    
        ASSERT_EQ(topStudents.size(), 4);
        EXPECT_EQ(topStudents[0].getName(), "Charlie");
        EXPECT_EQ(topStudents[1].getName(), "Alice");
        EXPECT_EQ(topStudents[2].getName(), "Diana");
        EXPECT_EQ(topStudents[3].getName(), "Bob"); 
    }

    TEST(CalculateCircumFerence_Test, SomeBasicTests){
        EXPECT_NEAR(calculateCircumFerence(5.3), 33.284, 0.01);
        EXPECT_NEAR(calculateCircumFerence(0.89), 5.5892, 0.01);
        EXPECT_NEAR(calculateCircumFerence(451), 2832.28, 0.01);        
    }

    class EmployeeTest : public ::testing::Test {
        protected:
            Employee employeeFirst;
            Employee employeeSecond;
            Employee employeeThird;
            
            EmployeeTest() :
                employeeFirst {"John", 33},
                employeeSecond {"Max"},
                employeeThird {63}
            {}

            virtual ~EmployeeTest() {}
    };

    TEST_F(EmployeeTest, TestNames){
        EXPECT_EQ(employeeFirst.getName(), "John");
        EXPECT_EQ(employeeSecond.getName(), "Max");
        EXPECT_EQ(employeeThird.getName(), "");
    }
    TEST_F(EmployeeTest, TestAges){
        EXPECT_EQ(employeeFirst.getAge(), 33);
        EXPECT_EQ(employeeSecond.getAge(), 0);
        EXPECT_EQ(employeeThird.getAge(), 63);
    }

    TEST(TestStaticAssert, testIfItWorkProperly){
        check_types();
        SUCCEED();
    }

    TEST(TestInitializerListFunction, PerfomanceCheck){
        std::vector<int> vecFirst {5,3,6,2};
        addElementsToVectorInitializerList({43,62,75,85}, vecFirst);
        EXPECT_EQ(vecFirst.size(), 8);
        EXPECT_EQ(vecFirst[7], 85);
    }

    TEST(TestUserLiterals, PerfomanceCheck) {
        EXPECT_EQ(5_min, 300);
        EXPECT_EQ(10_sec, 600);
        auto testString = "Hello World"_to_string;
        EXPECT_TRUE((std::is_same_v<decltype(testString), std::string>));
        EXPECT_EQ(testString.size(), 11);
        EXPECT_EQ(101100_bit_to_num, 44);
    }
} // namespace C11Features


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}