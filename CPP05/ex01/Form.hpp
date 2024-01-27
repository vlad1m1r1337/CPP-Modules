#ifndef CPPMODULESPROJECT_FORM_HPP
#define CPPMODULESPROJECT_FORM_HPP

#include "Bureaucrat.hpp"

class FailedSignForm : public exception {
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
    Form(const string &name);
    ~Form();
    void beSigned(const Bureaucrat& bur);
	const string getFormName() const;
	bool getFormSigned() const;
	 int getFormSignGrade() const;
	 int getFormExecGrade() const;
};

std::ostream &operator<<(std::ostream &ostream, const Form &obj);

#endif //CPPMODULESPROJECT_FORM_HPP
