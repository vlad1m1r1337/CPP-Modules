#include "ClapTrap.h"

int main() {
    ClapTrap cl("lol");
    ClapTrap clc("ok");
    cl.attack("123");
    clc.takeDamage(10);
    clc.beRepaired(2);
    cl.attack("123");
    clc.takeDamage(10);
    cl.attack("123");
    clc.takeDamage(10);
    return 0;
}