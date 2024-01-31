#ifndef CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP
#define CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    void execute(const Bureaucrat &bur);
	ShrubberyCreationForm(const string &name);
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
};

    void createThree(string name);

#endif
