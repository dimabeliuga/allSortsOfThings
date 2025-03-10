cmake_minimum_required(VERSION 3.20)
project(TrainingProgramme LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(LibraryForTesting src/Templates.cpp)
target_include_directories(LibraryForTesting PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE LibraryForTesting)

enable_testing()

add_subdirectory(tests)

# Добавление поддержки gcovr для отчетов покрытия
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Если gcovr не находится через PATH, можно указать HINTS:
    # find_program(GCOVR gcovr HINTS "C:/Users/<Ваше_имя>/AppData/Roaming/Python/Python39/Scripts")
    find_program(GCOVR gcovr)
    if(GCOVR)
        add_custom_target(coverage
            # Сначала сборка и запуск тестов
            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target test
            # Генерация HTML-отчета с помощью gcovr
            COMMAND ${GCOVR} -r ${PROJECT_SOURCE_DIR} --html --html-details -o ${CMAKE_BINARY_DIR}/coverage_report/index.html
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating code coverage report with gcovr"
        )
        message(STATUS "Coverage target added. Run 'make coverage' to generate coverage report")
    else()
        message(WARNING "gcovr not found. Coverage report generation will not be available")
    endif()
endif()