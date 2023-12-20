#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main() {
	AMateria *i = new Ice();
	cout << i->getType() << endl;

	AMateria *j = new Cure();
	cout << j->getType() << endl;

	AMateria c;
	cout << c.getType() << endl;

	return 0;
}
