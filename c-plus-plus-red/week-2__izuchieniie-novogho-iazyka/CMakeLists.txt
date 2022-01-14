cmake_minimum_required(VERSION 3.20)
project(izuchieniie-novogho-iazyka)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(izuchieniie-novogho-iazyka
        ${TARGET_SRC}
        ${TARGET_H})
