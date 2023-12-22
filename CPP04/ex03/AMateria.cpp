#include "AMateria.hpp"

string const & AMateria::getType() const {
	return _type;
}

AMateria::AMateria(string const & type) {
	_type = type;
//	cout << "AMaterial Constructor was called" << endl;
}

AMateria::AMateria() {
//	cout << "AMaterial Default Constructor was called" << endl;
}

AMateria::~AMateria() {
//	cout << "AMaterial Destructor was called" << endl;
}

AMateria::AMateria(const AMateria &copy) {
//	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria &other) {
//	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		this->_type = other._type;
		return (*this);
	}
	return *this;
}

void AMateria::use(ICharacter &target) {
	(void) target;
}
