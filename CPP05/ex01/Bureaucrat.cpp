#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(const Form& form) const {
    if (form.getFormSigned()) {
        cout << getName() << " signed " << form.getFormName() << endl;
    }
    else {
        cout << getName() << " couldn't sign " << form.getFormName() << " becuse reason" << endl;
    }
}

TooLowGrade::TooLowGrade() throw() {};

TooLowGrade::~TooLowGrade() throw() {};

const char* TooLowGrade::what() const throw()
{
    const char* message = "Too low grade";
    return message;
}

TooHighGrade::TooHighGrade() throw() {};

TooHighGrade::~TooHighGrade() throw() {};

const char* TooHighGrade::what() const throw()
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

Bureaucrat::Bureaucrat() {
    _name = "Vova";
    _grade = 1;
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

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj)
{
    std::cout << obj.getName() <<" ,bureaucrat grade " << obj.getGrade() << endl;
    return ostream;
}