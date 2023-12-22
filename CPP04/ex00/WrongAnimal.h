#ifndef CPPMODULESPROJECT_WRONGANIMAL_H
#define CPPMODULESPROJECT_WRONGANIMAL_H

#include "iostream"

class WrongAnimal {
protected:
	std::string type;
public:
	void makeSound() const;
	std::string getType() const ;
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal& operator=(const WrongAnimal &other);
};



#endif //CPPMODULESPROJECT_WRONGANIMAL_H
