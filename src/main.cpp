#include <iostream>
#include <cassert>
#include "SpecialContainer.h"

int main(){
    container<int, 5> intContainer;
    intContainer.setElements();
    intContainer.printElements();

    container<bool, 5> boolContainer;
    
    for(int32_t i = 0; i < boolContainer.getSize(); ++i){
        boolContainer.setElement(i, i % 2);
    }
    for(int32_t i = 0; i < boolContainer.getSize(); ++i){
        std::cout << std::boolalpha << boolContainer[i] << " ";
    }
    std::cout << std::endl;


    container<std::string, 5> stringContainer;
    for(size_t i = 0; i < stringContainer.getSize(); ++i){
        std::string element;
        std::cout << "Enter the element: ";
        std::cin.ignore();
        std::getline(std::cin, element);
        stringContainer.setElement(i, element.c_str());
    }

    for(size_t i = 0; i < stringContainer.getSize(); ++i){
        std::cout << stringContainer[i] << " ";
    }

    return 0;
}