#include "Error.hpp"

const char *Error::what() const throw() {
	const char* message = "Error";
	return message;
}

Error::Error() throw() {};

Error::~Error() throw() {};
