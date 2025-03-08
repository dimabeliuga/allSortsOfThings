#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <optional>
#include <string>
#include <memory>
#include <cassert>
#include <numeric>

namespace userImplementation{
    // it better to use const references in templates to avoid copying
    // because valuables can be classes or structs, and it is not recommended 
    // to copy them
    template<typename T>
    const T& max(const T& first, const T& second);

    template<typename T>
    std::optional<double> average(const T* container, size_t size);

    void outputAllNumberBits(int32_t num);
}


template<class T>
class UserContainer{
    private:
        std::unique_ptr<T[]> container;
        int32_t size;
    public:
        UserContainer(int32_t temp_size);
        UserContainer() = delete;
        UserContainer(const UserContainer&) = delete;
        UserContainer(const UserContainer&&) = delete;
        UserContainer& operator=(const UserContainer&) = delete;


        int32_t getSize()const;
        void fillContainerWithOneNumber(T number);
        void fillWithIota(T startNumber);
        T getValue(int32_t index)const;
        void setValue(int32_t index, T value);
        void printContainer()const;
};

class UserClass{
    private:
        std::string name;
        uint8_t age;
    public:
        UserClass(std::string name, uint8_t age): name(name), age(age){}

        friend bool operator>(const UserClass& first, const UserClass& second);
        friend bool operator<(const UserClass& first, const UserClass& second);
        friend double operator+(double num, const UserClass& first);
        friend std::ostream& operator<<(std::ostream& os, const UserClass& user);

        void printUserInformation()const;

        uint8_t getAge()const{
            return age;
        }
        std::string getName()const{
            return name;
        }
};

//* size is constant, so it can't be changed
template<class T, int32_t size>
class userContainerImpoved{
    private:
        std::unique_ptr<UserContainer<T>>container;
    public: 
        userContainerImpoved();
        void printContainer();
        int32_t getSize()const;
        void fillContainerWithOneNumber(T number);
        void fillWithIota(T startNumber);
        T getValue(int32_t index)const;
        void setValue(int32_t index, T value);
};

#include "Templates.inl"
/*     std::cout << "Max of 10 and 20: " << userImplementation::max(10, 20) << std::endl;
    std::cout << "Max of 324.34 and 564.123: " << userImplementation::max(324.34, 564.123) << std::endl;
    std::string firstString{"Hello"};
    std::string secondString{"World"};
    const std::string& result = userImplementation::max(firstString, secondString);
    std::cout << "Max of string and string: " << result << std::endl;
 */
#endif // TEMPLATES_H