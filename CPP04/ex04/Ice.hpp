#ifndef CPPMODULESPROJECT_ICE_HPP
#define CPPMODULESPROJECT_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	~Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& other);
};

#endif //CPPMODULESPROJECT_ICE_HPP
