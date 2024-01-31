#ifndef CPPMODULESPROJECT_BUREAUCRAT_HPP
#define CPPMODULESPROJECT_BUREAUCRAT_HPP

#include "iostream"
#include <stdexcept>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
using std::ofstream;
using std::ifstream;

class AForm;

class TooLowGrade : public std::exception
{
public:
    TooLowGrade() throw();

    ~TooLowGrade() throw();

    const char* what() const throw();
};

class TooHighGrade : public std::exception
{
public:
    TooHighGrade() throw();

    ~TooHighGrade() throw();

    const char* what() const throw();
};

class Bureaucrat {
private:
    string _name;
    int _grade;
    void checkErrors();
public:
    Bureaucrat();
    Bureaucrat(const string &name, int grade);

    int getGrade() const;

    void setGrade(int grade);

    const string &getName() const;

    void setName(const string &name);

    ~Bureaucrat();

    void signForm(const AForm& form) const;

	void executeForm(AForm& form);

    Bureaucrat& operator=(const Bureaucrat &other);

    Bureaucrat (const Bureaucrat &copy);
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj);
#endif
