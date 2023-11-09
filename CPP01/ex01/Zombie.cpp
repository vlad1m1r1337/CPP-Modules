#include "Zombie.h"

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << "DESTRUCTOR" << std::endl;
}

void Zombie::announce() {
    std::cout << _name << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}
