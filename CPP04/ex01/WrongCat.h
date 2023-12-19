//
// Created by Vladimir Gribkov on 12/19/23.
//

#ifndef CPPMODULESPROJECT_WRONGCAT_H
#define CPPMODULESPROJECT_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal{
public:
	void makeSound() const;

	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat& operator=(const WrongCat &other);
};


#endif //CPPMODULESPROJECT_WRONGCAT_H
