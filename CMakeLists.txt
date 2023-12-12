cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
        CPP03/ex01/ClapTrap.cpp
        CPP03/ex01/ClapTrap.h
        CPP03/ex01/main.cpp
        CPP03/ex01/ScavTrap.cpp
        CPP03/ex01/ScavTrap.h
)
