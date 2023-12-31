#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H

# include "Weapon.h"
# include "iomanip"

class HumanB {
private:
	std::string _name;
	Weapon *_weapon_type;
public:
	HumanB(std::string name);
	void attack();
	void setWeapon(Weapon &club);
};

#endif
