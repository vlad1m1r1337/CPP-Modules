#include "Cat.h"

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

Cat::Cat() {
	type = "cat";
	std::cout << "Cat constructor was called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->type = other.type;
		return (*this);
	}
	return *this;
}

Cat::Cat(const Cat &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}