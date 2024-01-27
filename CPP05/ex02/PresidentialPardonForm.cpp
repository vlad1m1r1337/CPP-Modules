#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("name") {}

PresidentialPardonForm::PresidentialPardonForm(const string &name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(const Bureaucrat &bur) {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		throw TooLowGrade();
	}
	if (!AForm::getFormSigned()) {
		throw NotSignedForm();
	}
	cout << bur.getName() << " has been pardoned by Zaphod Beeblebrox" << endl;
}
