#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "TemplateRequires.h"

template <typename T>
void output_optional(std::optional<T> opt){
    if(opt.has_value()){
        std::cout << "Result: " << opt.value() << std::endl;
    } else {
        std::cout << "Error: Division by zero" << std::endl;
    }
}

int main(){
    assert((sum(1, 2) == 3));
    std::cout << "Double sum: " << sum(1.1, 2.2) << std::endl;

    std::cout << "Less than int(char): " << std::boolalpha << less_than_int<char> << std::endl;
    std::cout << "Greater than int(long): " << std::boolalpha << greater_equal_than_int<long> << std::endl;
    std::string str;
    str.resize(3);
    std::cout << "Less than int(string): " << std::boolalpha << less_than_int<std::string> << "   Size = " << sizeof(str) << std::endl;
    std::vector<int> vec {1, 2, 3};
    vec.resize(3);
    std::cout << "Greater than int(std::vector<int>): " << std::boolalpha << greater_equal_than_int<std::vector<int>> << "      Size: " << sizeof(vec) << std::endl;

    std::cout << "Check type(int): " << std::boolalpha << check_type<int> << std::endl;
    std::cout << "Check type(double): " << std::boolalpha << check_type<double> << std::endl;
    std::cout << "Check type(char): " << std::boolalpha << check_type<char> << std::endl;
    std::cout << "Check type(long long): " << std::boolalpha << check_type<long long> << std::endl;
    std::cout << "Check type(unisgned int): " << std::boolalpha << check_type<unsigned int> << std::endl;
    
    std::cout << "\n Double size = " << sizeof(double) << std::endl;
    std::cout << "Long size = " << sizeof(long long) << std::endl;
    std::cout << "Int size = " << sizeof(int) << std::endl;
    
    const char* str2 = "Hello";
    const char* str3 = "World";

    std::cout << "Sum of strings = " << sum(std::string(str2), std::string(str3)) << std::endl;
    // sum(str, str2); // Error: no matching function for call to 'sum(const char*&, const char*&)'

    output_optional(calculator(1, 2));
    output_optional(calculator(1.1, 2.2));
    output_optional(calculator(1.1f, 2.2f));
    output_optional(calculator(1.1l, 2.2l));
    
    std::cout << "Is container(int) : " << std::boolalpha << is_container<int> << std::endl;
    std::cout << "Is container(char[]) : " << std::boolalpha << is_container<char[]> << std::endl;
    std::cout << "Is container(std::string) : " << std::boolalpha << is_container<std::string> << std::endl;
    std::cout << "Is container(std::vector<int>) : " << std::boolalpha << is_container<std::vector<int>> << std::endl;
    
    return 0;
}