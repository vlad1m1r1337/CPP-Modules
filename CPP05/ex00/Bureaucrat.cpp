#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const string &name, int grade) : _name(name), _grade(grade) {
    try {
        if (_grade < 1) {
            throw TooHighGrade();
        }
    }
    catch (const TooHighGrade& error) {
        cout << error.what() << endl;
    }
    try {
        if (_grade > 150) {
            throw TooLowGrade();
        }
    }
    catch (const TooLowGrade& err) {
        cout << err.what() << endl;
    }
}

Bureaucrat::~Bureaucrat() {

}

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
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj)
{

    std::cout << obj.getName() <<" ,bureaucrat grade " << obj.getGrade() << endl;
    return ostream;
}