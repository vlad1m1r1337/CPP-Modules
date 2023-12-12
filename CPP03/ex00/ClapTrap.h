//
// Created by Hasan on 11.12.2023.
//

#ifndef CPPMODULESPROJECT_CLAPTRAP_H
#define CPPMODULESPROJECT_CLAPTRAP_H

#include "iostream"

class ClapTrap {
private:
    std::string _name;
    int _hp;
    int _stamina;
    int _dmg;
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif //CPPMODULESPROJECT_CLAPTRAP_H
