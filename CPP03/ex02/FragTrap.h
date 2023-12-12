#ifndef CPPMODULESPROJECT_FRAGTRAP_H
#define CPPMODULESPROJECT_FRAGTRAP_H

#include "ClapTrap.h"
#include "ScavTrap.h"

class FragTrap : public ScavTrap{
public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};


#endif
