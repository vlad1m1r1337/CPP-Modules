#ifndef CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP
#define CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	void beSigned(const Bureaucrat& bur);
	PresidentialPardonForm(const string &name);
	PresidentialPardonForm();
	~PresidentialPardonForm();
};


#endif
