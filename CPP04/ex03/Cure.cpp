#include "Cure.hpp"

Cure* Cure::clone() const {
	Cure* cure = new Cure();
	return cure;
}

Cure::Cure() {
	_type = "cure";
//	cout << "Cure Constructor was called" << endl;
}

Cure::~Cure() {
//	cout << "Cure Destructor was called" << endl;
}

Cure::Cure(const Cure &copy) : AMateria(){
//	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure &other) {
//	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->_type = other._type;
		return (*this);
	}
	return *this;
}

void Cure::use(ICharacter &target) {
	cout << "* heals " <<  target.getName() << "\'s" << " wounds *" << endl;
}
