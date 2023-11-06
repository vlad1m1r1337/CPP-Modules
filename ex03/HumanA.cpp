#include "HumanA.h"

void HumanA::attack() {
	std::cout << _name << " attacks with his " << _weapon_type.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& club) : _name(name), _weapon_type(club) {
    std::cout << "Human " << name << " was called" << std::endl;
}
