#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

void	run() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new  Cat();
	const WrongAnimal* wA = new WrongCat();
	const WrongCat* wC = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wA->getType() << " " << std::endl;
	std::cout << wC->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	wC->makeSound();
	wA->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wA;
	delete wC;
}

int main() {
	run();
}