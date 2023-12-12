#include "ScavTrap.h"
#include "FragTrap.h"

int main() {
    FragTrap ft1("eblostrel");
    std::cout << ft1.getterHP() << std::endl;
    std::cout << ft1.getterStamina() << std::endl;
    std::cout << ft1.getterDmg() << std::endl;
    ft1.highFivesGuys();
    return 0;
}
