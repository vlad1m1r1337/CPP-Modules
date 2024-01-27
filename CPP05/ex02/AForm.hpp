#ifndef CPPMODULESPROJECT_FORM_HPP
#define CPPMODULESPROJECT_FORM_HPP

#include "Bureaucrat.hpp"

class FailedSignForm : public exception {
public:
	FailedSignForm() throw();

	~FailedSignForm() throw();

	const char* what() const throw();
};

class NotSignedForm : public exception {
public:
	NotSignedForm() throw();
	~NotSignedForm() throw();
	const char* what() const throw();
};

class AForm {
private:
	const string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	AForm(const string &name);
	AForm(const string &name, const int sign_grade, const int exec_grade);

	~AForm();

	virtual void beSigned(const Bureaucrat &bur) = 0;

	const string getFormName() const;

	bool getFormSigned() const;

	int getFormSignGrade() const;

	int getFormExecGrade() const;

	void setFormSigned(bool sign);
};

std::ostream &operator<<(std::ostream &ostream, const AForm &obj);

#endif //CPPMODULESPROJECT_FORM_HPP
