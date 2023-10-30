#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

# include <iomanip>

class Zombie {

private:


public:
	std::string _name;
	Zombie(std::string p_name)
	{
		_name = p_name;
	}
	void	announce();
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
};


#endif
