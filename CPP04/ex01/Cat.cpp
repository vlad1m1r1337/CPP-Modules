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
	std::cout << "Cat assignation operator called" << std::endl;
	if (&other != this) {
		std::cout << "Cat assignation operator called" << std::endl;
		*this->brain = *other.brain;
		return (*this);
	}
	return *this;
}

Cat::Cat(const Cat &copy) : Animal() {
	std::cout << "Copy constructor is called" << std::endl;
	type = "cat";
	brain = new Brain();
	*this = copy;
}
