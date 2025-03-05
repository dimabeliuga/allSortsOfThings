#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

namespace userImplementation{
    // it better to use const references in templates to avoid copying
    // because valuables can be classes or structs, and it is not recommended 
    // to copy them
    template<typename T>
    const T& max(const T& first, const T& second){
        return first > second ? first : second;
    }

    void outputAllNumberBits(int64_t num);

}


/*     std::cout << "Max of 10 and 20: " << userImplementation::max(10, 20) << std::endl;
    std::cout << "Max of 324.34 and 564.123: " << userImplementation::max(324.34, 564.123) << std::endl;
    std::string firstString{"Hello"};
    std::string secondString{"World"};
    const std::string& result = userImplementation::max(firstString, secondString);
    std::cout << "Max of string and string: " << result << std::endl;
 */
#endif // TEMPLATES_H