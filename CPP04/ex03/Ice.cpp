#include "Ice.hpp"

Ice* Ice::clone() const {
	Ice* ice = new Ice();
	return ice;
}

Ice::Ice() {
	_type = "ice";
	cout << "Ice Constructor was called" << endl;
}

Ice::~Ice() {

	cout << "Ice Destructor was called" << endl;
}

Ice::Ice(const Ice &copy) : AMateria(){
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

Ice& Ice::operator=(const Ice &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->_type = other._type;
		return (*this);
	}
	return *this;
}