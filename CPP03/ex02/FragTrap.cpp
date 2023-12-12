#include "FragTrap.h"
#include "ClapTrap.h"
#include "ScavTrap.h"

FragTrap::FragTrap(std::string name) : ScavTrap(name) {
    setterName(name);
    setterHP(100);
    setterStamina(100);
    setterDmg(30);
    std::cout << "FragTrap Constructor for " << name << " was called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor for was called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "HIGH F1VE GUUUUUUUUYYYYYSSSS" << std::endl;
}
