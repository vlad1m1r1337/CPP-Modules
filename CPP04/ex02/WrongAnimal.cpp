#include "WrongAnimal.h"

void WrongAnimal::makeSound() const {
	std::cout << "wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

WrongAnimal::WrongAnimal() {
	type = "no type";
	std::cout << "WrongAnimal constructor was called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor was called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->type = other.type;
		return (*this);
	}
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}
