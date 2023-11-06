#include "Weapon.h"
#include "HumanA.h"

//int main() {
//	Weapon myWeapon;
//	myWeapon.setType("Sword");
//
//	std::cout << "Weapon type: " << myWeapon.getType() << std::endl;
//	return 0;
//}

int main() {
    Weapon club = Weapon("crude spiked club");
    club.setType("Club Type");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

}