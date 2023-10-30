#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

# include <iomanip>

class Zombie {

private:
	std::string _name;
public:
	Zombie(std::string p_name);
	Zombie();
	void	announce();
//	Zombie* newZombie( std::string name );
};


#endif
