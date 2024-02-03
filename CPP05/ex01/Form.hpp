#ifndef CPPMODULESPROJECT_FORM_HPP
#define CPPMODULESPROJECT_FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
using std::ostream;
using std::exception;

class Form {
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
    Form();
    Form(const string &name, int sign_grade, int exec_grade);
    ~Form();
    void beSigned(const Bureaucrat& bur);
	const string getFormName() const;
	bool getFormSigned() const;
	int getFormSignGrade() const;
	int getFormExecGrade() const;

    Form (const Form &copy);
    Form &operator=(Form const &other);
};

ostream &operator<<(ostream &ostream, const Form &obj);

#endif
