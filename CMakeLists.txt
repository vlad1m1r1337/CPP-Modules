cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
        CPP01/ex03/HumanA.cpp
        CPP01/ex03/HumanA.h
        CPP01/ex03/HumanB.cpp
        CPP01/ex03/HumanB.h
        CPP01/ex03/main.cpp
        CPP01/ex03/Makefile
        CPP01/ex03/Weapon.cpp
        CPP01/ex05/Harl.cpp
        CPP02/ex00/Fixed.h
        CPP02/ex00/main.cpp
        CPP02/ex00/Fixed.cpp)
