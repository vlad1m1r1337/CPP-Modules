#include "Zombie.h"

Zombie* newZombie( std::string name ) {
	Zombie	*allocZombie = new Zombie(name);
	return allocZombie;
}

void randomChump( std::string name ) {
	Zombie randzomb;
	Zombie randomZombie(name);
	randomZombie.announce();
}

int main() {
	newZombie("Ashot");
	randomChump("Bruno");
}
