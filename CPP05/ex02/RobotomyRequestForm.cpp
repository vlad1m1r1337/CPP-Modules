#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &name) : AForm(name, 72, 45) {}

//void AForm::beSigned(const Bureaucrat &bur) {
//	if (bur.getGrade() > getFormSignGrade()) {
//		cout << bur.getName() << " couldn’t sign " << getFormName() << " because too low grade" <<  endl;
//		throw FailedSignForm();
//	}
//	else {
//		setFormSigned(true);
//		cout << bur.getName() << " signed " << getFormName() << endl;
//	}
//}

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



RobotomyRequestForm::RobotomyRequestForm() : AForm("name") {}

RobotomyRequestForm::~RobotomyRequestForm() {}
