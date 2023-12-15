#include "ScavTrap.h"

int main() {
    ScavTrap st1("e");
    ScavTrap st2("y");

    st1.attack("y");
    st2.takeDamage(20);
	st1.attack("y");
	st2.takeDamage(20);
	st1.guardGate();
    return 0;
}
