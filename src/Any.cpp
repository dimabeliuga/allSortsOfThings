/**
 * @file BoostAny.cpp
 * @author DB
 * @brief practise how to use boost any
 * See http://www.boost.org/libs/any for Documentation
 * @copyright Copyright (c) 2025
 * from c++17 std::any is available
 * void* is not type safe, better to use any
 */

#include <iostream>
#include <vector>
#include <string>
#include <any>

int main(){
    std::any first{std::make_any<int32_t>(4334)}; // int
    std::any second{std::make_any<std::string>("Hello")}; // string
    
    std::cout << "Sizeof int32_t = " << sizeof(int32_t) << '\n'; //4
    std::cout << "Sizeof any = " << sizeof(std::any) << '\n'; //64

    first.emplace<std::vector<int32_t>>({1,2,3,4,5,6,7,8,9,10});
    auto lambda = [](int32_t a, int32_t b)->int{return a + b;};
    first.emplace<decltype(lambda)>(lambda);

    first.reset(); // to empty std::any

    if(first.has_value()){ // check if std::any is empty
        std::cout << "First has value\n";
    } else {
        std::cout << "First is empty\n";
    }

    std::any third;
    std::cout << std::boolalpha << third.has_value() << '\n'; // false

    third = {std::make_any<int32_t>(342)};
    std::cout << std::boolalpha << third.has_value() << '\n'; // true

    third.reset();
    std::cout << std::boolalpha << third.has_value() << '\n'; // false

    std::any fourth;
    std::cout << std::boolalpha << (fourth.type() == typeid(void)) << '\n'; // true

    fourth = "Hello world";
    std::cout << std::boolalpha << (fourth.type() == typeid(const char*)) << '\n'; // true
    std::cout << "Fourth type = " << fourth.type().name() << '\n'; // char*
    try{
        std::string str = std::any_cast<const char*>(fourth);
        std::cout << "Fourth: " << str << '\n';
    } catch(const std::bad_any_cast& ex){
        std::cout << "Error: " << ex.what() << '\n';
    }

    return 0;
}