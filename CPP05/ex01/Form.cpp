#include "Form.hpp"

FailedSignForm::FailedSignForm() throw() {}

FailedSignForm::~FailedSignForm() throw() {}

const char* FailedSignForm::what() const throw()
{
    const char* message = "failed to sign form";
    return message;
}

void Form::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > _sign_grade) {
        cout << bur.getName() << " couldn’t sign " << _name << " because too low grade" <<  endl;
        throw FailedSignForm();
    }
    else {
        _signed = true;
        cout << bur.getName() << " signed " << _name << endl;
    }
}

std::ostream &operator<<(std::ostream &ostream, const Form &obj) {
	ostream << "Form's name - " << obj.getFormName();
    ostream << " Form's signed - " << obj.getFormSigned();
    ostream << " Form's sign grade - " << obj.getFormSignGrade();
    ostream << " Form's exec grade - " << obj.getFormExecGrade();
	return ostream;
}

const string Form::getFormName() const {
    return _name;
}

bool Form::getFormSigned() const {
    return _signed;
}
 int Form::getFormSignGrade() const {
    return _sign_grade;
}
 int Form::getFormExecGrade() const {
    return _exec_grade;
}

Form::Form(const string &name) : _name(name), _sign_grade(130), _exec_grade(130) {
    _signed = false;
}

Form::~Form() {}
