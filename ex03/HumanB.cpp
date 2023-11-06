#include "HumanB.h"

HumanB::void attack() {
	std::cout << _name << " attacks with his " << _weapon_type.getType() << std::endl;
}

HumanB::HumanB(std::string name, Weapon& club) : _name(name), _weapon_type(club) {
	std::cout << "Human " << name << " was called" << std::endl;
}

int HumanB::attack() {
	return 0;
}
