cmake_minimum_required(VERSION 3.20)
project(TrainingProgramme LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LibraryForTesting src/Templates.cpp)
target_include_directories(LibraryForTesting PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE LibraryForTesting)

enable_testing()

add_subdirectory(tests)