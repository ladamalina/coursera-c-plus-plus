cmake_minimum_required(VERSION 3.20)
project(chast-mnozhiestva)

set(CMAKE_CXX_STANDARD 14)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(chast-mnozhiestva
        ${TARGET_SRC}
        ${TARGET_H}
        main.cpp)
