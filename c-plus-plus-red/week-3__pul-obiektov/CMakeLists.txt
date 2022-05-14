cmake_minimum_required(VERSION 3.20)
project(week-3__pul-obiektov)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(week-3__pul-obiektov
        ${TARGET_SRC}
        ${TARGET_H})
