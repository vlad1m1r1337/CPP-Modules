#ifndef CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP
#define CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
	void beSigned(const Bureaucrat& bur);
	ShrubberyCreationForm(const string &name);
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
};


#endif
