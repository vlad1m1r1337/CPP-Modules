cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
    CPP07/ex01/main.cpp
        CPP07/ex01/whatever.hpp
)
