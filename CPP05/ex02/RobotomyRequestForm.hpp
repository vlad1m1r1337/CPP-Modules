#ifndef CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP
#define CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	void execute(const Bureaucrat &bur);
	RobotomyRequestForm(const string &name);
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
};


#endif
