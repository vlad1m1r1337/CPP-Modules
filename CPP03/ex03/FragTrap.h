#ifndef CPPMODULESPROJECT_FRAGTRAP_H
#define CPPMODULESPROJECT_FRAGTRAP_H

#include "ClapTrap.h"
#include "ScavTrap.h"

class FragTrap :virtual public ClapTrap {
public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);

	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &other);
};

#endif
