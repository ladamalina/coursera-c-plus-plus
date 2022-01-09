cmake_minimum_required(VERSION 3.20)
project(week-1__makros-update-field)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(week-1__makros-update-field
        ${TARGET_SRC}
        ${TARGET_H})
