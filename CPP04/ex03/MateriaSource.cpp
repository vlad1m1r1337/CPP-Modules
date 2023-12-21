#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* new_materia) {
	if (count < 4) {
		slots[count] = new_materia;
		count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (slots[i] != NULL && slots[i]->getType() == type) {
			cout << "Materia succesfully created" << endl;
			return slots[i]->clone();
		}
	}
	cout << "Failed to create Materia" << endl;
	return NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (slots[i] != NULL) {
			delete slots[i];
		}
	}
	cout << "MateriaSource destructor was called" << endl;
}

MateriaSource::MateriaSource() : count(0)  {
	for (int i = 0; i < 4; i++) {
		slots[i] = NULL;
	}
	cout << "MateriaSource constructor was called" << endl;
}


