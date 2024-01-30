#ifndef CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP
#define CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
//	void beSigned(const Bureaucrat &bur);
	void execute(const Bureaucrat &bur);
	RobotomyRequestForm(const string &name);
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();
};


#endif //CPPMODULESPROJECT_ROBOTOMYREQUESTFORM_HPP
