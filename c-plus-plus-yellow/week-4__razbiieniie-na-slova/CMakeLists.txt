cmake_minimum_required(VERSION 3.20)
project(razbiieniie-na-slova)

set(CMAKE_CXX_STANDARD 14)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(razbiieniie-na-slova
        ${TARGET_SRC}
        ${TARGET_H}
        main.cpp)
