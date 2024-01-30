#ifndef CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP
#define CPPMODULESPROJECT_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
//    void beSigned(const Bureaucrat &bur);
    void execute(const Bureaucrat &bur);
	PresidentialPardonForm(const string &name);
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
};


#endif
