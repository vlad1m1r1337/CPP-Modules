#ifndef CPPMODULESPROJECT_INTERN_HPP
#define CPPMODULESPROJECT_INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	class InvalidNameExeption : public exception
	{
	public:
		InvalidNameExeption() throw();
		~InvalidNameExeption() throw();
		const char* what() const throw();
	};
	Intern();
	~Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);

	AForm* makeForm(const string& name, const string& target);
};

#endif
