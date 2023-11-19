#ifndef CPPMODULESPROJECT_FIXED_H
#define CPPMODULESPROJECT_FIXED_H

#include "iostream"

class Fixed {
private:
	int _integer;
	static const int _st_const_int;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& OtherFixed);
    Fixed& operator = (const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
