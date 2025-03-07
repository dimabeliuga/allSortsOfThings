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
    const T& max(const T& first, const T& second){
        return first > second ? first : second;
    }

    template<typename T>
    std::optional<double> average(const T* container, size_t size){
        if(!size){
            return std::nullopt;
        }
        double sum = 0;
        for(size_t i = 0; i < size; ++i){
            sum = sum + container[i];
        }
        return sum / size;
    }

    void outputAllNumberBits(int64_t num);
}

template<class T>
class UserContainer{
    private:
        std::unique_ptr<T[]> container;
        int32_t size;
    public:
        UserContainer(int32_t temp_size) : size(temp_size){
            assert(size < 0);
            container = std::make_unique<T[]>(size);
        }

        int32_t getSize()const;
        void fillContainerWithOneNumber(T number);
        void fillWithIota(T startNumber);
        T getValue(int32_t index)const;
        void setValue(int32_t index, T value);
};

class UserClass{
    private:
        std::string name;
        uint8_t age;
    public:
        UserClass(std::string name, uint8_t age): name(name), age(age){}

        friend bool operator>(const UserClass& first, const UserClass& second){
            return first.age > second.age;
        }
        friend bool operator<(const UserClass& first, const UserClass& second){
            return first.age < second.age;
        }
        friend double operator+(double num, const UserClass& first){
            return num + first.age;
        }
        friend std::ostream& operator<<(std::ostream& os, const UserClass& user){
            os << "Name: " << user.name << std::endl;
            os << "Age: " << static_cast<int>(user.age) << std::endl;
            return os;
        }

        void printUserInformation()const;

        uint8_t getAge()const{
            return age;
        }
        std::string getName()const{
            return name;
        }
};



/*     std::cout << "Max of 10 and 20: " << userImplementation::max(10, 20) << std::endl;
    std::cout << "Max of 324.34 and 564.123: " << userImplementation::max(324.34, 564.123) << std::endl;
    std::string firstString{"Hello"};
    std::string secondString{"World"};
    const std::string& result = userImplementation::max(firstString, secondString);
    std::cout << "Max of string and string: " << result << std::endl;
 */
#endif // TEMPLATES_H

template <class T>
inline int32_t UserContainer<T>::getSize() const{
    return size;
    return 0;
}

template <class T>
inline void UserContainer<T>::fillContainerWithOneNumber(T number){
    std::fill(container.get(), container.get() + size, number);
}

template <class T>
inline void UserContainer<T>::fillWithIota(T startNumber){
    std::iota(container.get(), container.get() + size, startNumber);
}

template <class T>
inline T UserContainer<T>::getValue(int32_t index) const{
    assert(index < 0 && index >= size);
    return container[index];
}

template <class T>
inline void UserContainer<T>::setValue(int32_t index, T value){
    // assert(index < 0 && index >= size);
    if(index < 0 || index >= size){
        // throw std::out_of_range("Index is out of range");
        return ;
    }
    container[index] = value;
}
