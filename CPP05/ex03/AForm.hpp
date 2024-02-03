#ifndef CPPMODULESPROJECT_FORM_HPP
#define CPPMODULESPROJECT_FORM_HPP

#include "Bureaucrat.hpp"

class AForm {
private:
	const string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();

		~GradeTooLowException() throw();

		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();

		~GradeTooHighException() throw();

		const char* what() const throw();
	};
	AForm();
	AForm(const string &name, const int sign_grade, const int exec_grade);

	 virtual ~AForm();

	void beSigned(const Bureaucrat &bur);
	virtual void execute(const Bureaucrat &bur) const = 0;

	const string getFormName() const;

	bool getFormSigned() const;

	int getFormSignGrade() const;

	int getFormExecGrade() const;

	void setFormSigned(bool sign);

    AForm(const AForm &copy);

    AForm &operator=(AForm const &other);
};

std::ostream &operator<<(std::ostream &ostream, const AForm &obj);

#endif
