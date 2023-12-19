#ifndef CPPMODULESPROJECT_CAT_H
#define CPPMODULESPROJECT_CAT_H

#include "Animal.h"

class Cat : public Animal {

public:
	void makeSound() const;

	Cat();
	~Cat();
	Cat(const Cat &copy);
	Cat& operator=(const Cat &other);
};

#endif
