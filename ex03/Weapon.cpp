#include "Weapon.h"

const std::string& Weapon::getType() const {
	return (this->_type);
}

void Weapon::setType(const std::string& new_type) {
	_type = new_type;
}
