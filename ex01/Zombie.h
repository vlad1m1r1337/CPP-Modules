#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include <iostream>
#include <string>
#include <sstream>

class Zombie {

private:
    std::string _name;
public:
    Zombie();
    ~Zombie();
    void announce();
    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name );

#endif //CPP01_ZOMBIE_H
