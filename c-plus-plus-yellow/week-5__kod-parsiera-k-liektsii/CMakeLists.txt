cmake_minimum_required(VERSION 3.20)
project(week-5__kod-parsiera-k-liektsii)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(week-5__kod-parsiera-k-liektsii
        ${TARGET_SRC}
        ${TARGET_H})
