#include "Cat.h"

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

Cat::Cat() : Animal() {
	type = "cat";
    brain = new Brain();
	std::cout << "Cat constructor was called" << std::endl;
}

Cat::~Cat() {
    delete brain;
	std::cout << "Cat destructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		*this->brain = *other.brain;
		this->type = other.type;
		return (*this);
	}
	return *this;
}

Cat::Cat(const Cat &copy) : Animal() {
	std::cout << "Copy constructor is called" << std::endl;
	brain = new Brain(*copy.brain);
	type = "cat";
	(*this).operator=(copy);
}
