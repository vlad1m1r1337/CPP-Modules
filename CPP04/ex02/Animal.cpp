#include "Animal.h"

void Animal::makeSound() const {
	std::cout << "do nothing" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

Animal::Animal() {
	type = "no type";
	std::cout << "Animal constructor was called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor was called" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->type = other.type;
		return (*this);
	}
	return *this;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

void	Animal::setType(string type) {
	this->type = type;
}
