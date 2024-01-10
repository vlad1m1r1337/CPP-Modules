#include "Brain.h"

string Brain::getIdea(int index) {
    return ideas[index];
}

Brain::Brain() {
	cout << "Brain constructor called" << endl;
}

Brain::~Brain() {
	cout << "Brain desstructor called" << endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}

}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}


