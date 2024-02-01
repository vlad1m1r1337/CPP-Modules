#ifndef CPPMODULESPROJECT_INTERN_HPP
#define CPPMODULESPROJECT_INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);

	AForm* makeForm(string name, string target);
};

#endif
