cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
        CPP03/ex02/FragTrap.cpp
        CPP03/ex02/FragTrap.h
        CPP03/ex02/main.cpp
        CPP03/ex02/ClapTrap.cpp
        CPP03/ex02/ScavTrap.cpp
        CPP03/ex03/DiamondTrap.cpp
        CPP03/ex03/DiamondTrap.h
        CPP03/ex03/main.cpp
)
