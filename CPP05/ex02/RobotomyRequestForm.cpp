#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &target) : AForm(target, 72, 45) {}

void RobotomyRequestForm::execute(const Bureaucrat &bur) const {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		throw Bureaucrat::TooLowGrade();
	}
	if (!AForm::getFormSigned()) {
		cout << "form is not signed" << endl;
		return ;
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