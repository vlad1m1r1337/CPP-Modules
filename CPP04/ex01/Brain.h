#ifndef CPPMODULESPROJECT_BRAIN_H
#define CPPMODULESPROJECT_BRAIN_H

#include "Animal.h"

class Brain {
private:
	std::string ideas[100];
public:
    string getIdea(int index);

	Brain(const Brain &copy);
	Brain& operator=(const Brain &other);
	Brain();
	~Brain();
};


#endif //CPPMODULESPROJECT_BRAIN_H
