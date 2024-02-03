#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::InvalidNameExeption::InvalidNameExeption() throw() {}
Intern::InvalidNameExeption::~InvalidNameExeption() throw() {}

const char* Intern::InvalidNameExeption::what() const throw() {
	const char* message = "invalid form name";
	return message;
}

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const string &name, const string &target) {
	string forms[3] = {"shrubbery request", "robotomy request", "presidental pardon"};
	AForm* (*arr_forms[3])(string name) = {&ShrubberyCreationForm::clone, &RobotomyRequestForm::clone, &PresidentialPardonForm::clone};
	int i = 0;
	for (; (i < 3) && name != forms[i]; i++);
	if (i == 3) {
		cout << "couldn't create " << name << endl;
		throw InvalidNameExeption();
	}
	else {
		cout << "Intern creates " << name << endl;
		return (*arr_forms[i])(target);
	}
}
