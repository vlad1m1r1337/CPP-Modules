#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string name) : _hp(10), _stamina(1), _dmg(10) {
    _name = name;
    std::cout << "Constructor for " << _name << " was called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor for " << _name << " was called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_stamina <= 0) {
        std::cout << "No stamina for attack" << std::endl;
        return;
    }
    _stamina--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _dmg << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp <= 0) {
		std::cout << "Claptrap is already death" << std::endl;
		return ;
	}
    if (_stamina <= 0) {
        std::cout << "No stamina for repairing" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " repaires " << amount << " hp" << std::endl;
    _stamina--;
    _hp = _hp + amount;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hp <= 0) {
        std::cout << "Claptrap is already death" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage" << std::endl;
    _hp = _hp - amount;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    *this = copy;
    std::cout << "Copy constructor is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->_name = other._name;
    this->_hp = other._hp;
    this->_stamina = other._stamina;
    this->_dmg = other._dmg;
    return (*this);
}
