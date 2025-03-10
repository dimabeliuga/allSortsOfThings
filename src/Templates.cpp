#include "Templates.h"

bool operator>(const UserClass& first, const UserClass& second){
    return first.getAge() > second.getAge();
}

bool operator<(const UserClass& first, const UserClass& second){
    return first.getAge() < second.getAge();
}
double operator+(double num, const UserClass& first){
    return num + first.getAge();
}
std::ostream& operator<<(std::ostream& os, const UserClass& user){
    os << "Name: " << user.getName() << std::endl;
    os << "Age: " << static_cast<int>(user.getAge()) << std::endl;
    return os;
}



void userImplementation::outputAllNumberBits(int32_t num){
    for(int i = 0; i < 64; ++i){
        bool bit = num & (1 << i);
        std::cout << bit;
    }
}

void UserClass::printUserInformation() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << static_cast<int>(age) << std::endl;
}

