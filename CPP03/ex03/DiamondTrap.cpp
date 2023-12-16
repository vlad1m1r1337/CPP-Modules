#include "ClapTrap.h"
#include "ScavTrap.h"
#include "DiamondTrap.h"

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
	std::cout << "Diamond Constructor called" << std::endl;
	this->_name = name;
	_hp = FragTrap::_hp;
	_stamina = ScavTrap::_stamina;
	_dmg = FragTrap::_dmg;
	ClapTrap::_name = name + "_clap_name";
	std::cout << _name << std::endl;
	std::cout << _hp << std::endl;
	std::cout << _stamina << std::endl;
	std::cout << _dmg << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : FragTrap(copy), ScavTrap(copy) {
	*this = copy;
	std::cout << "Copy constructor is called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_stamina = other._stamina;
	this->_dmg = other._dmg;
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << this->_name << std::endl;
	std::cout << ClapTrap::_name << std::endl;
}

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {}

