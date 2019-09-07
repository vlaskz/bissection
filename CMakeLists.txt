cmake_minimum_required(VERSION 3.14)
project(bissection C)

set(CMAKE_C_STANDARD 11)

add_executable(bissection main.c)
target_link_libraries(bissection m)