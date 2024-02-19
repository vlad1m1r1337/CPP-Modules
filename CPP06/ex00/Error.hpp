#ifndef CPPMODULESPROJECT_ERROR_HPP
#define CPPMODULESPROJECT_ERROR_HPP

#include "iostream"
using std::exception;

class Error : public exception {
public:
	Error() throw();
	~Error() throw();
	const char* what() const throw();
};

#endif
