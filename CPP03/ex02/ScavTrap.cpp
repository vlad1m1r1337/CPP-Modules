#include "ClapTrap.h"
#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    setterName(name);
    setterHP(100);
    setterStamina(50);
    setterDmg(20);
    std::cout << "ScavTrap Constructor for " << name << " was called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Constructor was called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
