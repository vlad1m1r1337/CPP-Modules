cmake_minimum_required(VERSION 3.26)
project(CPPModulesProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPPModulesProject
        CPP05/ex02/AForm.cpp
        CPP05/ex02/Bureaucrat.cpp
        CPP05/ex02/main.cpp
        CPP05/ex02/PresidentialPardonForm.cpp
        CPP05/ex02/RobotomyRequestForm.cpp
)
