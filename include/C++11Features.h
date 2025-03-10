#ifndef C__11Features_H
#define C__11Features_H

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <initializer_list>

//* auto type 
class Student{
    private:
        std::string name;
        int32_t age;
        double GPA;
        int32_t extraActivities;
    public:
        Student(std::string temp_name,
                int32_t temp_age, 
                double temp_GPA,
                int32_t temp_extraActivities)
                : name(temp_name), age(temp_age),
                  GPA(temp_GPA), extraActivities(temp_extraActivities) 
                  {
                  }
        Student() {}

        friend auto calculateScore(const Student& student) {
            return 0.5 * student.GPA + 0.3 * student.extraActivities + 0.2 * student.age;
        }

        friend auto filterStudents(std::vector<Student>& students, double threshold){
            std::vector<Student> filteredStudents;

            std::copy_if(students.begin(), students.end(), std::back_inserter(filteredStudents), 
                [threshold](Student& student)
                {
                    return calculateScore(student) >= threshold;
                });
        
            std::sort(filteredStudents.begin(), filteredStudents.end(), 
                      [](const Student& studentFirst, const Student& studentSecond)
                    {
                        return calculateScore(studentFirst) > calculateScore(studentSecond);
                    });
            return filteredStudents;
        }

        std::string getName() { return name; }
};

//* constexpr

constexpr double getConstatnPi(){ return 3.14; }
constexpr double calculateCircumFerence(const double& radius){
    return 2 * radius * getConstatnPi();
}

constexpr void check_types() {
    static_assert(sizeof(short) > sizeof(char), "Short size is less then char size");
    static_assert(sizeof(int) > sizeof(short), "int size is less then short size");
    static_assert(sizeof(double) > sizeof(int), "double size is less then int size");
}

template<typename T>
void addElementsToVectorInitializerList(const std::initializer_list<T> list, std::vector<T>& vec) {
    if(!list.size()){
        return ;
    }
    vec.insert(vec.end(), list.begin(), list.end());
}
/*
int main(){
    constexpr radius = 2.34;
    constexp circumFerence = calculateCircumFerence(radius);
}
*/

//* delegating constructors
class Employee final{
    private:
        std::string name;
        uint32_t age;
    public:
        explicit Employee(const std::string_view temp_name, const uint32_t temp_age)
                : name(temp_name), age(temp_age) {}

        explicit Employee(const std::string_view temp_name) : Employee(temp_name, 0) {}
        explicit Employee(const uint32_t temp_age) : Employee("", temp_age) {}
        
        Employee() = delete;
        Employee(const Employee&) = delete;
        Employee(const Employee&&) = delete;

        public:
            std::string getName() const noexcept{ return name; }
            uint32_t getAge() const noexcept {return age; }
};


//*user literals

unsigned long long operator "" _min(unsigned long long minutes){
    return minutes * 60;
}

unsigned long long operator "" _sec(unsigned long long seconds) {
    return seconds * 60;
}

std::string operator "" _to_string(const char* str, size_t size) {
    return std::string(str, size);
}

unsigned long long operator "" _bit_to_num(const char* str) {
    unsigned long long result {};
    size_t size = std::strlen(str);

    for(size_t i = 0; i < size; ++i) {
        assert((str[i] == '0' || str[i] == '1') && "Bits can be only 1 or 0");
        result |= (str[i] - '0') << (size - i - 1);
    }
    return result;
}

#endif