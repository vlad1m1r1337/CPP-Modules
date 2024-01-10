#include "WrongCat.h"

void WrongCat::makeSound() const {
	std::cout << "wrong's cat meow" << std::endl;
}

WrongCat::WrongCat() {
	type = "wrong cat";
	std::cout << "WrongCat constructor was called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor was called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->type = other.type;
		return (*this);
	}
	return *this;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal() {
	std::cout << "Copy constructor is called" << std::endl;
	this->type = copy.type;
	*this = copy;
}