#include "AForm.hpp"

AForm::GradeTooLowException::GradeTooLowException() throw() {};

AForm::GradeTooLowException::~GradeTooLowException() throw() {};

const char* AForm::GradeTooLowException::what() const throw()
{
    const char* message = "Too low grade";
    return message;
}

AForm::GradeTooHighException::GradeTooHighException() throw() {};

AForm::GradeTooHighException::~GradeTooHighException() throw() {};

const char* AForm::GradeTooHighException::what() const throw()
{
    const char* message = "Too high grade";
    return message;
}

void AForm::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > _sign_grade) {
        throw GradeTooLowException();
    }
    else {
        _signed = true;
    }
}

std::ostream &operator<<(std::ostream &ostream, const AForm &obj) {
	ostream << "Form's name - " << obj.getFormName();
    ostream << " Form's signed - " << obj.getFormSigned();
    ostream << " Form's sign grade - " << obj.getFormSignGrade();
    ostream << " Form's exec grade - " << obj.getFormExecGrade();
	return ostream;
}

const string AForm::getFormName() const {
    return _name;
}

bool AForm::getFormSigned() const {
    return _signed;
}
 int AForm::getFormSignGrade() const {
    return _sign_grade;
}
 int AForm::getFormExecGrade() const {
    return _exec_grade;
}

void AForm::setFormSigned(bool sign) {
    _signed = sign;
}

AForm::AForm() : _name("name"), _sign_grade(130), _exec_grade(130) {
    _signed = false;
}

AForm::AForm(const std::string &name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    _signed = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy)
        : _name(copy._name),
          _signed(copy._signed),
          _sign_grade(copy._sign_grade) ,
          _exec_grade(copy._exec_grade) {
    *this = copy;
}

AForm &AForm::operator=(AForm const &other) {
    _signed = other._signed;
    return *this;
}
