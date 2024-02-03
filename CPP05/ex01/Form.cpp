#include "Form.hpp"

Form::GradeTooLowException::GradeTooLowException() throw() {};

Form::GradeTooLowException::~GradeTooLowException() throw() {};

const char* Form::GradeTooLowException::what() const throw()
{
    const char* message = "Too low grade";
    return message;
}

Form::GradeTooHighException::GradeTooHighException() throw() {};

Form::GradeTooHighException::~GradeTooHighException() throw() {};

const char* Form::GradeTooHighException::what() const throw()
{
    const char* message = "Too high grade";
    return message;
}

void Form::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > _sign_grade) {
        throw GradeTooLowException();
    }
    else {
        _signed = true;
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

Form::Form(const string &name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    _signed = false;
    if (_sign_grade < 1) {
        throw GradeTooHighException();
    }
    if (_sign_grade > 150) {
        throw GradeTooLowException();
    }
	if (_exec_grade < 1) {
		throw GradeTooHighException();
	}
	if (_exec_grade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form() : _name("form"), _signed(false), _sign_grade(1), _exec_grade(1) {}

Form::~Form() {}

Form::Form(const Form &copy)
        : _name(copy._name),
        _signed(copy._signed),
        _sign_grade(copy._sign_grade) ,
        _exec_grade(copy._exec_grade) {
        *this = copy;
}

Form &Form::operator=(Form const &other) {
    _signed = other._signed;
    return *this;
}
