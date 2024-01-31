#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &name) : AForm(name, 72, 45) {}

void RobotomyRequestForm::execute(const Bureaucrat &bur) {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		cout << "the robotomy failed" << endl;
		throw TooLowGrade();
	}
	if (!AForm::getFormSigned()) {
		cout << "the robotomy failed" << endl;
		throw NotSignedForm();
	}
	cout << bur.getName() << " has been robotomized successfully 50% of the time" << endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("name", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (&other != this) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
    *this = copy;
}