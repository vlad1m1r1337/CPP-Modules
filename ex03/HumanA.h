#ifndef CPP01_HUMANA_H
#define CPP01_HUMANA_H

# include "Weapon.h"
# include "iomanip"
# include "iostream"

class HumanA {
private:
	std::string _name;
	Weapon& _weapon_type;
public:
	HumanA(std::string name, Weapon& club);
	void attack();
};


#endif
