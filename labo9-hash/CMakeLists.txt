cmake_minimum_required(VERSION 3.5)
project(algo2_labo_hash)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)


add_executable(correrTests ${SOURCE_FILES} tests/diccHash-tests.cpp tests/diccHash-tests.cpp src/DiccHash.h)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests diccHash_test)
