#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > AForm::getFormExecGrade()) {
		throw TooLowGrade();
	}
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("name") {}

ShrubberyCreationForm::ShrubberyCreationForm(const string &name) : AForm(name, 145, 137) {}

