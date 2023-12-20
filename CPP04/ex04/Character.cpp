#include "Character.hpp"

Character::Character() {
	cout << "Character Constructor was called" << endl;
}

Character::~Character() {
	cout << "Character Destructor was called" << endl;
}

Character::Character(const Character &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

//Character& Character::operator=(const Character &other) {
//	std::cout << "Assignation operator called" << std::endl;
//	if (&other != this) {
//		this->_type = other._type;
//		return (*this);
//	}
//	return *this;
//}
