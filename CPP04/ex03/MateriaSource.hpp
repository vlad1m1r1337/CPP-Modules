#ifndef CPPMODULESPROJECT_MATERIASOURCE_HPP
#define CPPMODULESPROJECT_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *slots[4];
	int count;
public:
	void learnMateria(AMateria* new_materia);
	AMateria* createMateria(std::string const & type);

	MateriaSource();
	~MateriaSource();
};

#endif
