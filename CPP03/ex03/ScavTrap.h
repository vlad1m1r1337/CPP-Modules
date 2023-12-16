#ifndef CPPMODULESPROJECT_SCAVTRAP_H
#define CPPMODULESPROJECT_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap :virtual public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &other);
};

#endif
