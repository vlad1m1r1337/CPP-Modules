#ifndef CPPMODULESPROJECT_CHARACTER_HPP
#define CPPMODULESPROJECT_CHARACTER_HPP

#include "iostream"
#include "ICharacter.hpp"

using std::cout;
using std::string;
using std::cin;
using std::endl;


class Character : public ICharacter {
public:

	Character();
	~Character();
	Character(const Character& copy);
//	Character& operator=(const Character& other);
};


#endif
