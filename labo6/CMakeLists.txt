cmake_minimum_required(VERSION 3.5)
project(algo2_labo_clase3)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h)

file(GLOB SOURCE_FILES_ABB src/ABB.h)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)

add_executable(correrTests ${SOURCE_FILES} tests/conjunto-tests.cpp tests/conjunto-tests.cpp src/Conjunto.h)
add_executable(correrTestsABB ${SOURCE_FILES_ABB} tests/ABBtests.cpp)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)
target_link_libraries(correrTestsABB gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests conjunto_test)
add_test(correrTestsABB ABB_test)
