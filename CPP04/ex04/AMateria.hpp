#ifndef CPPMODULESPROJECT_AMATERIA_HPP
#define CPPMODULESPROJECT_AMATERIA_HPP

#include "iostream"
using std::cout;
using std::string;
using std::cin;
using std::endl;

class AMateria {
protected:
	string _type;
public:
	AMateria(string const & type);
	string const & getType() const; //Returns the materia type
//	virtual AMateria* clone() const = 0;
//	virtual void use(ICharacter& target);

	AMateria();
	~AMateria();
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& other);
};


#endif
