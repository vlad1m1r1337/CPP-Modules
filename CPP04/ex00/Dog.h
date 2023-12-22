#ifndef CPPMODULESPROJECT_DOG_H
#define CPPMODULESPROJECT_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	void makeSound() const;

	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog& operator=(const Dog &other);
};

#endif
