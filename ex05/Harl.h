#ifndef CPP01_HARL_H
#define CPP01_HARL_H

#include "iostream"


class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    void complain( std::string level);
};


#endif
