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

class FailedSignForm : public std::exception {
public:
	FailedSignForm() throw();

	~FailedSignForm() throw();

	const char* what() const throw();
};

class Form {
private:
    const string _name;
    bool _signed;
    const int _sign_grade;
    const int _exec_grade;

public:
    Form();
    Form(const string &name);
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
