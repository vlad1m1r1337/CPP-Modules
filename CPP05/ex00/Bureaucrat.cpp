#include "Bureaucrat.hpp"

Bureaucrat::TooLowGrade::TooLowGrade() throw() {};

Bureaucrat::TooLowGrade::~TooLowGrade() throw() {};

const char* Bureaucrat::TooLowGrade::what() const throw()
{
    const char* message = "Too low grade";
    return message;
}

Bureaucrat::TooHighGrade::TooHighGrade() throw() {};

Bureaucrat::TooHighGrade::~TooHighGrade() throw() {};

const char* Bureaucrat::TooHighGrade::what() const throw()
{
    const char* message = "Too high grade";
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

const string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade) {
    _grade = grade;
    checkErrors();

}

void Bureaucrat::increment() {
	int cur_grade = getGrade() - 1;
	if (cur_grade > 150) {
		throw TooLowGrade();
	}
	setGrade(cur_grade);
}


void Bureaucrat::decrement() {
	int cur_grade = getGrade() + 1;
	if (cur_grade < 1) {
		throw TooHighGrade();
	}
	setGrade(cur_grade);
}

Bureaucrat::Bureaucrat() : _name("Vova"){
    _grade = 1;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (&other != this) {
        this->_grade = other._grade;
        return *this;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj)
{

    std::cout << obj.getName() <<", bureaucrat grade " << obj.getGrade() << endl;
    return ostream;
}
