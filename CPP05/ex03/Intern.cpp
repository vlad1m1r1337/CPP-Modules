#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern &other) {
	return *this;
}

AForm* Intern::makeForm(string name, string target) {
	string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	void (AForm::*arr_forms[3])(void) = {&ShrubberyCreationForm::clone, &RobotomyRequestForm::clone, &PresidentialPardonForm::clone};
	for (int i = 0; i < 2; i++) {
		if (name == "shrubbery creation") {
			(this->*arr_forms[0])();
		}
		if (name == "robotomy request") {
			(this->*arr_forms[1])();
		}
		if (name == "presidental pardon") {
			(this->*arr_forms[2])();
		}
	}
}
