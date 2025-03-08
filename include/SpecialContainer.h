#ifndef SPECIAL_CONTAINER_H
#define SPECIAL_CONTAINER_H

#include <string>
#include <memory>
#include <iostream>
#include <cassert>
#include <bitset>

//* redefinition the function addElement depending on the type of the arguments
template<typename T>
T addElement(T first, T second);

int addElement(int first, int second);
std::string addElement(std::string first, std::string second);

template<class T, int32_t size>
class container{
    private:
        std::unique_ptr<T[]> array;
    public:
        container();
        void setElements();
        void printElements()const;
        int32_t getSize()const;
        T getElement(int32_t index)const;
        void setElement(int32_t index, T value);
        const T& operator[](int32_t index)const;
};

template<int32_t size>
class container<bool, size>{
    private:
        std::unique_ptr<std::bitset<size>> array;
    public:
        container();
        void setElement(int32_t index, bool value);
        bool getElement(int32_t index)const;
        int32_t getSize()const;
        bool operator[](int32_t index)const;
};

template<class T, int32_t size>
class container<T*, size>{
    private:
        std::unique_ptr<T[]> array;
    public:
        container();
        void setElement(int32_t index, T* value);
        T* getElement(int32_t index)const;
        int32_t getSize()const;
        T* operator[](int32_t index)const;
};

#include "SpecialContainer.inl"


#endif // SPECIAL_CONTAINER_H
