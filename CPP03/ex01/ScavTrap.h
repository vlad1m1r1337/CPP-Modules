#ifndef CPPMODULESPROJECT_SCAVTRAP_H
#define CPPMODULESPROJECT_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void guardGate();
};

#endif
