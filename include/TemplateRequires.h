#ifndef TEMPLATE_REQUIRES_H
#define TEMPLATE_REQUIRES_H

#include <iostream>
#include <type_traits>
#include <concepts>
#include <optional>

//* concepts
template <typename T>
concept less_than_int = sizeof(T) < sizeof(int);

template <typename T>
concept greater_equal_than_int = sizeof(T) >= sizeof(int);

template <typename T>
concept less_equal_than_long_long = sizeof(T) <= sizeof(long long);

template <typename T>
concept check_type = greater_equal_than_int<T> && less_equal_than_long_long<T>;

template <typename T>
concept check_type_for_sum_function = requires(T t) {
    { t + t } -> std::same_as<T>;
};


template <typename T>
concept operation = requires (T a, T b) {
    { a + b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a * b } -> std::same_as<T>;
};

template <typename T>
concept is_container = requires(T container, int container_size){
    container[container_size];
};

void user_command(int32_t& command){
    std::cout << "0 - Add\n";
    std::cout << "1 - Subtract\n";
    std::cout << "2 - Multiply\n";
    std::cout << "3 - Divide\n";

    std::cout << "Enter command: ";
    std::cin >> command;
}

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

//* This function will only accept int or double types
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




#endif // TEMPLATE_REQUIRES_H