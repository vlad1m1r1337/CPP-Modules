#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("name") {}

PresidentialPardonForm::PresidentialPardonForm(const string &name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

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

void PresidentialPardonForm::execute(const Bureaucrat &bur) {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		throw TooLowGrade();
	}
	if (!AForm::getFormSigned()) {
		throw NotSignedForm();
	}
	cout << bur.getName() << " has been pardoned by Zaphod Beeblebrox" << endl;
}
