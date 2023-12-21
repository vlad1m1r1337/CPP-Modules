#ifndef CPPMODULESPROJECT_CHARACTER_HPP
#define CPPMODULESPROJECT_CHARACTER_HPP

#include "iostream"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

using std::cout;
using std::string;
using std::cin;
using std::endl;

class Character : public ICharacter {
private:
	string _name;
	AMateria *slots[4];
	AMateria *ground[100];
public:
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	string const & getName() const;

	Character(string name);
	Character();
    virtual ~Character();
	Character(const Character& copy);
	//	Character& operator=(const Character& other);
};


#endif
