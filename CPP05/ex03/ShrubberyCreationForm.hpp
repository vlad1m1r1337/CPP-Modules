#ifndef CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP
#define CPPMODULESPROJECT_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    void execute(const Bureaucrat &bur) const;
	ShrubberyCreationForm(const string &target);
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	static AForm* clone(string name);
};

    void createThree(string name);

#endif
