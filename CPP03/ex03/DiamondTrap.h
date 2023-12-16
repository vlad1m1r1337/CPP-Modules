#ifndef CPPMODULESPROJECT_DIAMONDTRAP_H
#define CPPMODULESPROJECT_DIAMONDTRAP_H

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	void whoAmI();

	~DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap& operator=(const DiamondTrap &other);
	void	attack(const std::string& target);
};


#endif //CPPMODULESPROJECT_DIAMONDTRAP_H
