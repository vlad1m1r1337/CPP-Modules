#ifndef CPPMODULESPROJECT_BUREAUCRAT_HPP
#define CPPMODULESPROJECT_BUREAUCRAT_HPP

#include "iostream"
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

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

	int getGrade() const;

    void setGrade(int grade);

    const string &getName() const;

    void setName(const string &name);

    Bureaucrat(const string &name, int grade);

	Bureaucrat();

    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat &other);

    Bureaucrat (const Bureaucrat &copy);

	void increment();

	void decrement();
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &obj);
#endif
