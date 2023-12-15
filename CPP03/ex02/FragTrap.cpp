#include "FragTrap.h"
#include "ClapTrap.h"
#include "ScavTrap.h"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hp = 100;
    _stamina = 100;
    _dmg = 30;
    std::cout << "FragTrap Constructor for " << name << " was called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor was called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "HIGH F1VE GUUUUUUUUYYYYYSSSS" << std::endl;
}
