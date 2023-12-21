#include "Cure.hpp"

Cure* Cure::clone() const {
	Cure* cure = new Cure();
	return cure;
}

Cure::Cure() {
		_type = "Cure";
	cout << "Ice Constructor was called" << endl;
}

Cure::~Cure() {
	cout << "Ice Destructor was called" << endl;
}

Cure::Cure(const Cure &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->_type = other._type;
		return (*this);
	}
	return *this;
}