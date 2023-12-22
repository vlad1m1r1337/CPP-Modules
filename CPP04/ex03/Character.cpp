#include "Character.hpp"

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (slots[i] == NULL) {
			slots[i] = m;
			cout << "Materia equiped succesfully" << endl;
			return;
		}
	}
	cout << "Failed to equip Materia" << endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !slots[idx]) {
		cout << "Unequipping failed" << endl;
		return ;
	}
	for (int i = 0; i < 100; i++) {
		if (ground[i] == NULL) {
			ground[i] = slots[idx];
			cout << "Slot unequipped" << endl;
			return;
		}
	}
	cout << "Stop it.Get some Help" << endl;
}

void Character::use(int idx, ICharacter& target) {
	if(slots[idx] == NULL) {
		cout << "Index or target not exist" << endl;
		return;
	}
	slots[idx]->use(target);
}

string const & Character::getName() const{
	return _name;
}

Character::Character(string name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	for (int i = 0; i < 4; i++)
		ground[i] = NULL;
	cout << "Character Constructor was called" << endl;
}

Character::Character() {
	_name = "";
	for (int i = 0; i < 4; i ++) {
		slots[i] = NULL;
	}
	cout << "Character Constructor was called" << endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i ++) {
		delete slots[i];
	}
	cout << "Character Destructor was called" << endl;
}

Character::Character(const Character &copy) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}


Character& Character::operator=(const Character &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this) {
		_name = other._name;
		for (int i = 0; i < 4; ++i) {
			slots[i] = other.slots[i];
		}
		for (int i = 0; i < 100; ++i) {
			ground[i] = other.ground[i];
		}
		return (*this);
	}
	return *this;
}
