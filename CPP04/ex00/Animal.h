#ifndef CPPMODULESPROJECT_ANIMAL_H
#define CPPMODULESPROJECT_ANIMAL_H

#include "iostream"

class Animal {
protected:
	std::string type;
public:
	virtual void makeSound() const;
	std::string getType() const ;
	Animal();
	virtual ~Animal();
	Animal(const Animal &copy);
	Animal& operator=(const Animal &other);
};

#endif
