#include "AForm.hpp"

NotSignedForm::NotSignedForm() throw() {}

NotSignedForm::~NotSignedForm() throw() {}

const char* NotSignedForm::what() const throw()
{
	const char* message = "form is not signed";
	return message;
}

FailedSignForm::FailedSignForm() throw() {}

FailedSignForm::~FailedSignForm() throw() {}

const char* FailedSignForm::what() const throw()
{
    const char* message = "failed to sign form";
    return message;
}

void AForm::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() > _sign_grade) {
        cout << bur.getName() << " couldn’t sign " << _name << " because too low grade" <<  endl;
        throw FailedSignForm();
    }
    else {
        _signed = true;
        cout << bur.getName() << " signed " << _name << endl;
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

AForm::AForm(const string &name) : _name(name), _sign_grade(130), _exec_grade(130) {
    _signed = false;
}

AForm::AForm(const std::string &name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    _signed = false;
}

AForm::~AForm() {}
