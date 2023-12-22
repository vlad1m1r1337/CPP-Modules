#ifndef CPPMODULESPROJECT_ICHARACTER_HPP
#define CPPMODULESPROJECT_ICHARACTER_HPP

#include "AMateria.hpp"
#include "iostream"
using std::string;
class  AMateria;

class ICharacter {
public:
	virtual ~ICharacter();
	virpulltual string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
