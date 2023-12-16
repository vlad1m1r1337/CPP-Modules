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
    std::cout << "ScavTrap Destructor was called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
    *this = copy;
    std::cout << "Copy constructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->_name = other._name;
    this->_hp = other._hp;
    this->_stamina = other._stamina;
    this->_dmg = other._dmg;
    return (*this);
}

ScavTrap::ScavTrap() : ClapTrap() {}