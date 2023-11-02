#include "Zombie.h"

Zombie* newZombie( std::string name ) {
	return (new Zombie(name));
}

void randomChump( std::string name ) {
	Zombie randomZombie(name);
	randomZombie.announce();
}

int main() {
	Zombie *MallocZombie = newZombie("Tom");
	MallocZombie->announce();
	randomChump("John");
	delete MallocZombie;
	return 0;
}
