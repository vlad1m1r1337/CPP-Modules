#ifndef CPPMODULESPROJECT_CAT_H
#define CPPMODULESPROJECT_CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
private:
    Brain *brain;
public:
	void makeSound() const;

	Cat();
	~Cat();
	Cat(const Cat &copy);
	Cat& operator=(const Cat &other);
};

#endif
