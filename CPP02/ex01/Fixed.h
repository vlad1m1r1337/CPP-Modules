#ifndef CPPMODULESPROJECT_FIXED_H
#define CPPMODULESPROJECT_FIXED_H

#include "iostream"
#include <math.h>

class Fixed {
private:
	int _integer;
	static const int _st_const_int;
public:
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed();
	Fixed(int num);
	Fixed(float num);
	~Fixed();
	Fixed(const Fixed& OtherFixed);
    Fixed& operator = (const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj);
#endif
