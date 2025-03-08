#include "SpecialContainer.h"

//* redefinition the function addElement depending on the type of the arguments
template <typename T>
inline T addElement(T first, T second){
    return first + second;
}

//* class container implementation with all types
template<class T, int32_t size>
container<T, size>::container(){
    array = std::make_unique<T[]>(size);
}

template<class T, int32_t size>
void container<T, size>::setElements(){
    for(int32_t i = 0; i < size; ++i){
        std::cout << "Enter the element: ";
        std::cin >> array[i];
    }
}

template<class T, int32_t size>
void container<T, size>::printElements()const{
    for(int32_t i = 0; i < size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T, int32_t size>
inline int32_t container<T, size>::getSize() const{
    return size;
}

template<class T, int32_t size>
T container<T, size>::getElement(int32_t index)const{
    assert((index >= 0 && index < size && "The index is out of range"));
    return array[index];
}

template<class T, int32_t size>
void container<T, size>::setElement(int32_t index, T value){
    assert((index >= 0 && index < size && "The index is out of range"));
    array[index] = value;
}

template<class T, int32_t size>
const T& container<T, size>::operator[](int32_t index)const{
    return array[index];
}


//* improved class container implementation with bool type
template<int32_t size>
container<bool, size>::container(){
    array = std::make_unique<std::bitset<size>>();
}

template<int32_t size>
void container<bool, size>::setElement(int32_t index, bool value){
    assert((index >= 0 && index < size && "The index is out of range"));
    array->set(index, value);
}

template<int32_t size>
bool container<bool, size>::getElement(int32_t index)const{
    assert(index >= 0 && index < size && "The index is out of range");
    return array->test(index);
}

template<int32_t size>
int32_t container<bool, size>::getSize()const{
    return size;
}

template<int32_t size>
bool container<bool, size>::operator[](int32_t index)const{
    return getElement(index);
}

//* class container implementation with pointer type
template <class T, int32_t size>
container<T*, size>::container(){
    std::cout << "Pointer type" << std::endl;
    array = std::make_unique<T[]>(size);
}

template<class T, int32_t size>
void container<T*, size>::setElement(int32_t index, T* value){
    assert(index >= 0 && index < size && "The index is out of range");
    array[index] = *value;
}

template<class T, int32_t size>
T* container<T*, size>::getElement(int32_t index)const{
    assert(index >= 0 && index < size && "The index is out of range");
    return array[index];
}

template<class T, int32_t size>
int32_t container<T*, size>::getSize()const{
    return size;
}

template<class T, int32_t size>
T* container<T*, size>::operator[](int32_t index)const{
    assert(index >= 0 && index < size && "The index is out of range");
    return getElement(index);
}

