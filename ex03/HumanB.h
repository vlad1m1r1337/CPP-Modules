#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H

# include "Weapon.h"
# include "iomanip"

class HumanB {
private:
	HumanB(std::string name, Weapon &club);

	std::string _name;
	Weapon *_weapon_type;
public:
	attack();
	void setWeapon(Weapon club);
};

#endif
