#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string p_name) {
	std::cout << "Zombie constructor called" << std::endl;
	_name = p_name;
}

Zombie::~Zombie() {
	{
		std::cout << "Zombie " << _name << " deleted" << std::endl;
	}
}

void Zombie::announce() {
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
