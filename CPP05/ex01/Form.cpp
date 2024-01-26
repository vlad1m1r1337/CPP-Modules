#include "Form.hpp"

void Form::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > _sign_grade) {
        cout << "GradeTooLowException" << endl;
    }
}

Form::Form(const string &name) : _name(name), _sign_grade(130), _exec_grade(130) {
    _signed = false;
}

Form::~Form() {}
