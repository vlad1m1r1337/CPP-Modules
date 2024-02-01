#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::TooLowGrade::TooLowGrade() throw() {};

Bureaucrat::TooLowGrade::~TooLowGrade() throw() {};

const char* Bureaucrat::TooLowGrade::what() const throw()
{
	const char* message = "Too low bureaucrat grade";
	return message;
}

Bureaucrat::TooHighGrade::TooHighGrade() throw() {};

Bureaucrat::TooHighGrade::~TooHighGrade() throw() {};

const char* Bureaucrat::TooHighGrade::what() const throw()
{
	const char* message = "Too high bureaucrat grade";
	return message;
}

void Bureaucrat::checkErrors() {
    if (_grade < 1) {
        throw TooHighGrade();
    }
    if (_grade > 150) {
        throw TooLowGrade();
    }
}

Bureaucrat::Bureaucrat(const string &name, int grade) : _name(name), _grade(grade) {
    cout << "\e[34mConstructor for " << _name << " was called\e[0m" << endl;
    checkErrors();
}

Bureaucrat::~Bureaucrat() {}

const string &Bureaucrat::getName() const {
    return _name;
}

void Bureaucrat::setName(const string &name) {
    _name = name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade) {
    _grade = grade;
    checkErrors();

}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj)
{
    std::cout << obj.getName() <<" ,bureaucrat grade " << obj.getGrade() << endl;
    return ostream;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		cout << getName() << " signed " << form.getFormName() << endl;
	}
	catch (const exception& e) {
		cout << getName() << " couldn’t sign "<< form.getFormName() << " because " << e.what() << endl;
	}
}

void Bureaucrat::executeForm(AForm& form) {
	try {
		form.execute(*this);
		cout << this->getName() << " executed " << form.getFormName() << endl;
	}
	catch(const exception& e) {
		cout << this->getName() << " cannot execute " << form.getFormName() << " because " << e.what() << endl;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (&other != this) {
        this->_name = other._name;
        this->_grade = other._grade;
        return *this;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat::Bureaucrat() {
    _name = "Vova";
    _grade = 1;
}

void Bureaucrat::increment() {
	int cur_grade = getGrade() + 1;
	if (cur_grade > 150) {
		throw TooLowGrade();
	}
	setGrade(cur_grade);
}


void Bureaucrat::decrement() {
	int cur_grade = getGrade() - 1;
	if (cur_grade < 1) {
		throw TooHighGrade();
	}
	setGrade(cur_grade);
}
