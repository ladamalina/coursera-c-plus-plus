cmake_minimum_required(VERSION 3.20)
project(week-4__gruppirovka-strok-po-priefiksu)

set(CMAKE_CXX_STANDARD 14)
file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(week-4__gruppirovka-strok-po-priefiksu
        ${TARGET_SRC}
        ${TARGET_H}
        find_starts_with_char.cpp)
