#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {
	Animal a;


	cout << a.getType() << endl;
	a.setType("lalka");
	cout << a.getType() << endl;

	Animal b(a);

	cout << b.getType() << endl;
}