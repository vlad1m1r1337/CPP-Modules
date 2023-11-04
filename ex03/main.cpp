#include "Weapon.h"

int main() {
	Weapon myWeapon;

	myWeapon.setType("Sword");

	std::cout << "Weapon type: " << myWeapon.getType() << std::endl;
	return 0;
}
