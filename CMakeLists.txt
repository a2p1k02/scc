cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME scc)

file(GLOB PROJECT_FILES
    include/*.h
    src/*.c
)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

