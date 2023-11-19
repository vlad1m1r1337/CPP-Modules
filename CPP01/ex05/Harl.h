#ifndef CPP01_HARL_H
#define CPP01_HARL_H

#include "iostream"
#include <cstdlib>

class Harl {
private:
	std::string _level;
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
	Harl();
    void complain(std::string level);
};

#endif
