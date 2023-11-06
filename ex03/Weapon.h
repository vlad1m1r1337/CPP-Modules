#ifndef CPP01_WEAPON_H
#define CPP01_WEAPON_H

# include "iomanip"
# include <iostream>
class Weapon {
private:
	std::string _type;
public:
	const std::string& getType() const;
	void setType(const std::string& new_type);
    Weapon(std::string weapon);
};

#endif
