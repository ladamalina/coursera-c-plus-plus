cmake_minimum_required(VERSION 3.20)
project(week-4__pieriebor-pieriestanovok)

set(CMAKE_CXX_STANDARD 14)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(week-4__pieriebor-pieriestanovok
        ${TARGET_SRC}
        ${TARGET_H}
        main.cpp)
