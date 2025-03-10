#ifndef TEMPLATEREQUIRES_INL
#define TEMPLATEREQUIRES_INL

#include "TemplateRequires.h"

template <operation T>
std::optional<T> calculator(T a, T b) {
    int32_t command{};
    user_command(command);

    switch (command)
    {
    case 0:
        return a + b;
        break;
    case 1:
        return a - b;
        break;
    case 2:
        return a * b;
        break;
    case 3:
        if(b == 0){
            return std::nullopt;
        }
        return a / b;
        break;
    default:
        std::cout << "Invalid command" << std::endl;
        return std::nullopt;
    }
}

/* template <typename T> requires std::is_same<T, int>::value || std::is_same<T, double>::value
T sum(T a, T b) {
    return a + b;
} */

// template <typename T>
// T sum(T a, T b) requires check_type_for_sum_function<T> 
template <check_type_for_sum_function T> // shorten version
T sum(T a, T b) {
    return a + b;
}

#endif