cmake_minimum_required(VERSION 3.10)
project(GoogleTestExample)

set(CMAKE_CXX_STANDARD 11)

# Find GoogleTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_add test_add.cpp)

# Link GoogleTest libraries
target_link_libraries(test_add ${GTEST_LIBRARIES} pthread)