cmake_minimum_required(VERSION 3.2)

project(projectName VERSION 0.0.1
            DESCRIPTION "just tusk"
            LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)

add_executable(run main.cpp)
