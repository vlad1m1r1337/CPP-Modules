#ifndef CPPMODULESPROJECT_FORM_HPP
#define CPPMODULESPROJECT_FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
    const string _name;
    bool _signed;
    int _sign_grade;
    int _exec_grade;

public:
    Form(const string &name);
    ~Form();
    void beSigned(const Bureaucrat& bur);
};


#endif //CPPMODULESPROJECT_FORM_HPP
