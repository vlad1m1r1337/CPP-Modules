#include "Dog.h"

void Dog::makeSound() const {
	std::cout << "gav" << std::endl;
}

Dog::Dog() {
	type = "dog";
	std::cout << "Dog constructor was called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor was called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->type = other.type;
		return (*this);
	}
	return *this;
}

Dog::Dog(const Dog &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	this->type = copy.type;
}
