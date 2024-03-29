#ifndef CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP
#define CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	void execute(const Bureaucrat &bur) const;
	RobotomyRequestForm(const string &target);
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
};


#endif
