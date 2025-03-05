#include <iostream>
#include <optional>
#include <vector>
#include <fstream>

template<typename T, typename U>
std::optional<decltype(std::declval<T>() / std::declval<U>())> divideTwoNumbers(T firstNum, U secondNum){
    if(firstNum == 0){
        return std::nullopt;
    }
    return firstNum / secondNum;
}

template<typename T>
std::optional<T> findNumber(const std::vector<T>&& vec, T number){
    for(const auto& elem : vec){
        if(elem == number){
            return elem;
        }
    }
    return std::nullopt;
}

std::optional<std::string> readTextFromFile(const std::string& fileName){
    std::ifstream file(fileName);
    if(!file.is_open()){
        return std::nullopt;
    }
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return text;
}
int main(){
    std::optional<int> firstOptional;

    if(firstOptional.has_value()){
        std::cout << "firstOptional has value: " << firstOptional.value() << std::endl;
    } else {
        std::cout << "firstOptional has no value" << std::endl;
    }

    std::optional<std::string> secondOptional;
    std::string str = secondOptional.value_or("default value");
    secondOptional = str;

    if(secondOptional){
        std::cout << "secondOptional has value: " << secondOptional.value() << std::endl;
    } else {
        std::cout << "secondOptional has no value" << std::endl;
    }

    auto firstResult = divideTwoNumbers(10, 5);
    if(firstResult.has_value()){
        std::cout << "Result: " << firstResult.value() << std::endl;
        std::cout << "Type of result: " << typeid(firstResult.value()).name() << std::endl;
    }
    
    auto secondResult = divideTwoNumbers(332, 42.0);
    if(secondResult.has_value()){
        std::cout << "Result: " << secondResult.value() << std::endl;
        std::cout << "Type of result: " << typeid(secondResult.value()).name() << std::endl;
    } else {
        std::cout << "Cannot divide by zero" << std::endl;
    }

    auto numberPositionInVector = findNumber(std::vector<int>{1, 2, 3, 4, 5}, 3);
    if(numberPositionInVector.has_value()){
        std::cout << "Number found in vector: " << numberPositionInVector.value() << std::endl;
    } else {
        std::cout << "Number not found in vector" << std::endl;
    }

    auto textFromFile = readTextFromFile("text.txt");
    if(textFromFile.has_value()){
        std::cout << "Text from file: " << textFromFile.value() << std::endl;
    } else {
        std::cout << "Cannot read text from file" << std::endl;
    }
    
    return 0;
}

/* 
bool checkPowersOfThree(int n) { //leetcode task 1780
    if(n == 1) return true;
    if(n % 3 == 0){
        return checkPowersOfThree(n / 3);
    } else if(n % 3 == 1){
        return checkPowersOfThree(n - 1);
    } else {
        return false;
    }
}
 */
