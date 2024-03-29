#ifndef CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP
#define CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    void execute(const Bureaucrat &bur) const;
    PresidentialPardonForm();
	PresidentialPardonForm(const string &target);
	virtual ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	static AForm* clone(string name);
};

#endif
