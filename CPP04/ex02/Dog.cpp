#include "Dog.h"


void Dog::makeSound() const {
	std::cout << "gav" << std::endl;
}

Dog::Dog() {
	type = "dog";
    brain = new Brain();
	std::cout << "Dog constructor was called" << std::endl;
}

Dog::~Dog() {
    delete brain;
	std::cout << "Dog destructor was called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->brain = other.brain;
		this->type = other.type;
		return (*this);
	}
	return *this;
}

Dog::Dog(const Dog &copy) : Animal() {
	std::cout << "Copy constructor is called" << std::endl;
	brain = new Brain();
	type = "dog";
	*this = copy;
}
