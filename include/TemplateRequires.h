#ifndef TEMPLATE_REQUIRES_H
#define TEMPLATE_REQUIRES_H

#include <iostream>
#include <type_traits>
#include <concepts>
#include <optional>
#include <cstdint>

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

template <typename T>
concept is_pointer = requires(T pointer, int num) {
    {pointer[num]};
    {pointer + num} -> std::same_as<T>;
    {pointer - num} -> std::same_as<T>;
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
std::optional<T> calculator(T a, T b);

//* This function will only accept int or double types
template <check_type_for_sum_function T> // shorten version
T sum(T a, T b);

#include "TemplateRequires.inl"


#endif // TEMPLATE_REQUIRES_H