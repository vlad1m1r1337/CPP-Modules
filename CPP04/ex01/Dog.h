#ifndef CPPMODULESPROJECT_DOG_H
#define CPPMODULESPROJECT_DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
private:
    Brain *brain;
public:
	void makeSound() const;

	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog& operator=(const Dog &other);
};

#endif
