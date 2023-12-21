#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void run() {
	AMateria *i = new Ice();
	cout << i->getType() << endl;


	AMateria *j = new Cure();
	cout << j->getType() << endl;

	AMateria *mat_ice = i->clone();
	cout << mat_ice->getType() << endl;

	AMateria *mat_cure = j->clone();
	cout << mat_cure->getType() << endl;

	delete i;
	delete j;
	delete mat_cure;
	delete mat_ice;

}












int main() {
	run();
	system("leaks ex03");
	return 0;
}

//int main()
//{
//	IMateriaSource* src = new MateriaSource();
//	src->learnMateria(new Ice());
//	src->learnMateria(new Cure());
//	ICharacter* me = new Character("me");
//	AMateria* tmp;
//	tmp = src->createMateria("ice");
//	me->equip(tmp);
//	tmp = src->createMateria("cure");
//	me->equip(tmp);
//	ICharacter* bob = new Character("bob");
//	me->use(0, *bob);
//	me->use(1, *bob);
//	delete bob;
//	delete me;
//	delete src;
//	return 0;
//}