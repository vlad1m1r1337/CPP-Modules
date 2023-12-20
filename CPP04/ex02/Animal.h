#ifndef CPPMODULESPROJECT_ANIMAL_H
#define CPPMODULESPROJECT_ANIMAL_H

# define ARR_SIZE 10

#include "iostream"
using std::cout;
using std::endl;
using std::cin;
using std::string;

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
	void setType(string type);
};

#endif
