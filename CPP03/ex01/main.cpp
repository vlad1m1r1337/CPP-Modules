#include "ClapTrap.h"
#include "ScavTrap.h"

int main() {
    ScavTrap st1("ebatel228");
    ScavTrap st2("ya_puknul");
    st1.guardGate();

    st1.attack("ya_puknul");
    st2.takeDamage(20);
    return 0;
}
