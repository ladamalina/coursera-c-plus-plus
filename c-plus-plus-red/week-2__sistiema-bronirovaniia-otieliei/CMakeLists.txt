cmake_minimum_required(VERSION 3.20)
project(sistiema-bronirovaniia-otieliei)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(sistiema-bronirovaniia-otieliei
        ${TARGET_SRC}
        ${TARGET_H})
