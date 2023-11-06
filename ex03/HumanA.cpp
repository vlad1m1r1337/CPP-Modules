#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon& club) : _name(name), _weapon_type(club) {
    std::cout << "Human " << name << " was called" << std::endl;
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon_type.getType() << std::endl;
}
