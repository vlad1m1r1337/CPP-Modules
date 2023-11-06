#include "Weapon.h"

Weapon::Weapon(std::string weapon) {
    std::cout << "Constructor weapon " << weapon << " called" << std::endl;
}

const std::string& Weapon::getType() const {
	return (this->_type);
}

void Weapon::setType(const std::string& new_type) {
	_type = new_type;
}
