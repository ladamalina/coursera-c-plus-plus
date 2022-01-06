cmake_minimum_required(VERSION 3.20)
project(nabor-fighur)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(nabor-fighur
        ${TARGET_SRC}
        ${TARGET_H})
