#ifndef CPPMODULESPROJECT_ICE_HPP
#define CPPMODULESPROJECT_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice* clone() const;

	Ice();
	~Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& other);
};

#endif
