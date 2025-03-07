#include "Templates.h"

void userImplementation::outputAllNumberBits(int64_t num){
    for(int i = 0; i < 64; ++i){
        bool bit = num & (1 << i);
        std::cout << bit;
    }
}

void UserClass::printUserInformation() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << static_cast<int>(age) << std::endl;
}

