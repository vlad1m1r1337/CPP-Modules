#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("name", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const string &target) : AForm(target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &bur) {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		throw Bureaucrat::TooLowGrade();
	}
	if (!AForm::getFormSigned()) {
		cout << "form is not signed" << endl;
		return ;
	}
	cout << bur.getName() << " has been pardoned by Zaphod Beeblebrox" << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (&other != this) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
    *this = copy;
}
