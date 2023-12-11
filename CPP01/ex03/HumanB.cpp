#include "HumanB.h"

void HumanB::attack() {
//    if (!_weapon_type) {
//        return ;
//    }
	std::cout << _name << " attacks with his " << _weapon_type->getType() << std::endl;
}

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "Human " << "constructor" << " was called" << std::endl;
}
void HumanB::setWeapon(Weapon &club) {
	_weapon_type = &club;
}
