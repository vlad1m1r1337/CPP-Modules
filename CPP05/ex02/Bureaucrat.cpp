#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(const AForm& form) const {
    if (form.getFormSigned()) {
        cout << getName() << " signed " << form.getFormName() << endl;
    }
    else {
        cout << getName() << " couldn't sign " << form.getFormName() << " becuse reason" << endl;
    }
}

void Bureaucrat::executeForm(AForm& form) {
	try {
		form.execute(*this);
		cout << this->getName() << " executed " << form.getFormName() << endl;
	}
	catch (const TooLowGrade& e) {
		cout << e.what() << endl;
		cout << this->getName() << " cannot execute " << form.getFormName() << " because " << e.what() << endl;
	}
	catch (const NotSignedForm& e2) {
		cout << e2.what() << endl;
		cout << this->getName() << " cannot execute " << form.getFormName() << " because " << e2.what() << endl;
	}
	catch (const FailedSignForm& e3) {
		cout << e3.what() << endl;
		cout << this->getName() << " cannot execute " << form.getFormName() << " because " << e3.what() << endl;
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
