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

class Bureaucrat {
private:
    string const _name;
    int _grade;
    void checkErrors();
public:
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

    Bureaucrat();
    Bureaucrat(const string &name, int grade);

    int getGrade() const;

    void setGrade(int grade);

    const string &getName() const;

    void setName(const string &name);

	void increment();

	void decrement();

    ~Bureaucrat();

    void signForm(AForm& form);

	void executeForm(AForm const &form);

    Bureaucrat& operator=(const Bureaucrat &other);

    Bureaucrat (const Bureaucrat &copy);
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj);
#endif
