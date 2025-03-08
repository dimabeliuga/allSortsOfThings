#ifndef TEMPLATE_INL
#define TEMPLATE_INL

#include <optional>
#include "Templates.h"

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
}

template<typename T>
UserContainer<T>::UserContainer (int32_t temp_size) : size(temp_size){
    //* assert is not necessary, because if size less than 0, the programme will crash anyway
    //assert(size < 0);
    container = std::make_unique<T[]>(size);
}

template <class T>
inline int32_t UserContainer<T>::getSize() const{
    return size;
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
    assert(index >= 0 && index < size && "The index is out of range");
    return container[index];
}

template <class T>
inline void UserContainer<T>::setValue(int32_t index, T value){
    assert(index >= 0 && index < size && "The index is out of range");
    container[index] = value;
}

template <class T>
inline void UserContainer<T>::printContainer() const{
    for(int32_t i = 0; i < size; ++i){
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template<class T, int32_t size>
userContainerImpoved<T, size>::userContainerImpoved(){
    container = std::make_unique<UserContainer<T>>(size);
}

template<class T, int32_t size>
inline void userContainerImpoved<T,size>::printContainer(){
    container->printContainer();
}

template<class T, int32_t size>
inline int32_t userContainerImpoved<T, size>::getSize()const {
    return size;
}

template<class T, int32_t size>
inline void userContainerImpoved<T, size>::fillContainerWithOneNumber(T number){
    container->fillContainerWithOneNumber(number);
}

template<class T, int32_t size>
inline void userContainerImpoved<T, size>::fillWithIota(T startNumber){
    container->fillWithIota(startNumber);
}

template<class T, int32_t size>
inline T userContainerImpoved<T, size>::getValue(int32_t index)const{
    return container->getValue(index);
}

template<class T, int32_t size>
inline void userContainerImpoved<T, size>::setValue(int32_t index, T value){
    container->setValue(index, value);
}

#endif // TEMPLATE_INL