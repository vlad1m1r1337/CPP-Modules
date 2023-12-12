#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string &name) : _name(name), _hp(10), _stamina(1), _dmg(10) {
    std::cout << "ClapTrap Constructor for " << _name << " was called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor for " << _name << " was called" << std::endl;
}

std::string ClapTrap::getterName() {
    return _name;
}

void ClapTrap::setterName(std::string& name) {
    _name = name;
}

int ClapTrap::getterHP() {
    return _hp;
}

void ClapTrap::setterHP(int hp) {
    _hp = hp;
}

int ClapTrap::getterStamina() {
    return _stamina;
}

void ClapTrap::setterStamina(int stamina) {
    _stamina = stamina;
}


int ClapTrap::getterDmg() {
    return _stamina;
}

void ClapTrap::setterDmg(int dmg) {
    _dmg = dmg;
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

