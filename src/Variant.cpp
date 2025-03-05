/**
 * @file Variant.cpp
 * @author DB
 * @brief practise to work with std::variant
 * https://cengizhanvarli.medium.com/std-variant-in-c-c2fc83d34efe
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <variant>


int main(){
    // how to create a variant
    std::variant<uint32_t, int32_t, double, std::string> myVariant;
    
    // check if the variant is valueless by exception
    if(myVariant.valueless_by_exception()){
        std::cout << "myVariant is valueless by exception\n";
        myVariant = 5;
        std::cout << std::get<int>(myVariant) << '\n';
        myVariant = 3.14;
        std::cout << std::get<double>(myVariant) << '\n';
        myVariant = "Hello";
        std::cout << std::get<std::string>(myVariant) << '\n';
        myVariant.emplace<uint32_t>(5);
        std::cout << std::get<uint32_t>(myVariant) << '\n';
    }
    
    myVariant = 334u;
    // another method how to initialize a variant
    myVariant.emplace<uint32_t>(334u);

    // get the index of the variant
    std::cout << "MyVarian index(from 0 to 4): " << myVariant.index() << '\n';
    try{
        // check if the variant holds a specific type
        if(std::holds_alternative<uint32_t>(myVariant)){
            std::cout << "myVariant holds an uint32_t\n";
        } else if(std::holds_alternative<double>(myVariant)){
            std::cout << "myVariant holds a double\n";
        } else if(std::holds_alternative<std::string>(myVariant)){
            std::cout << "myVariant holds a string\n";
        } else if(std::holds_alternative<int32_t>(myVariant)){
            std::cout << "myVariant holds an unsigned int32_t\n";
        } else {
            std::cout << "myVariant holds something else\n";
        }
    } catch(const std::bad_variant_access& ex){
        std::cout << "Error: " << ex.what() << '\n';
    }
    
    std::variant<int, double> myVariant2 = 5;
    std::variant<int, double> myVariant3 = 3.14;
    // myVariant2.int swap myVariant3.double
    // new myVariant.double = 5, myVariant2.int = 3.14
    std::swap(myVariant2, myVariant3);
    std::cout << "myVariant2: " << std::get<double>(myVariant2) << '\n';
    std::cout << "myVariant3: " << std::get<int>(myVariant3) << '\n';

    return EXIT_SUCCESS;
}
