cmake_minimum_required(VERSION 3.16)

set(PROJECT "DiscreteLogarithm")
project(${PROJECT})
set(CMAKE_CXX_STANDARD 20)
add_executable(
        ${PROJECT}
        main.cpp
        operations.h
        tools/exceptions.h
        tools/conversions.h tools/conversions.cpp
        hashtable/table.h hashtable/table.cpp
)
target_link_libraries(${PROJECT} gmp gmpxx)
