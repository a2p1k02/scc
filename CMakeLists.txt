cmake_minimum_required(VERSION 3.28)

project(scc LANGUAGES C)

set(CMAKE_C_STANDARD 11)

file(GLOB sources
     include/*.h
     src/*.c
)

add_executable(scc ${sources})
