#ifndef CPPMODULESPROJECT_CURE_HPP
#define CPPMODULESPROJECT_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure* clone() const;

	Cure();
	~Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& other);
};

#endif
