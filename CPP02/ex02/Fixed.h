#ifndef CPPMODULESPROJECT_FIXED_H
#define CPPMODULESPROJECT_FIXED_H

#include "iostream"
#include <cmath>

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
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;
	bool operator>(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	Fixed& operator++ (void);
	Fixed& operator-- (void);
	Fixed operator++ (int);
	Fixed operator-- (int);
	static Fixed max(const Fixed& c1, const Fixed &c2);
	static Fixed min(const Fixed& c1, const Fixed &c2);
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj);

Fixed operator-(const Fixed& c1, const Fixed& c2);
Fixed operator*(const Fixed& c1, const Fixed& c2);
Fixed operator/(const Fixed& c1, const Fixed& c2);
Fixed operator+(const Fixed& c1, const Fixed& c2);

#endif
