cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
        CPP04/ex03/main.cpp
        CPP04/ex03/Ice.cpp
        CPP04/ex03/AMateria.cpp
        CPP04/ex03/Cure.cpp
        CPP04/ex03/MateriaSource.cpp
        CPP04/ex03/Character.cpp
        CPP04/ex03/ICharacter.cpp
)
