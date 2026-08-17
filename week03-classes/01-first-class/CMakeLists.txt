cmake_minimum_required(VERSION 3.20)

project(first_class LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first_class
    main.cpp
    src/led.cpp
)

target_include_directories(first_class PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)