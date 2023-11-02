#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name ) {
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << i;
        std::string s = ss.str();
        std::string new_name = name + s;
        zombies[i].setName(new_name);
    }
    return zombies;
}