#include "Fixed.h"

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj)
{

	std::cout << obj.toFloat();
	return ostream;
}

const int Fixed::_st_const_int = 8;

float Fixed::toFloat( void ) const {
	return static_cast<float>(_integer) / (1 << _st_const_int);
}

int Fixed::toInt( void ) const {
	return _integer >> _st_const_int;
}

Fixed::Fixed() {
	std::cout << "Default constructor called " << std::endl;
}

Fixed::Fixed(int num) {
    _integer = num << _st_const_int;
	std::cout << "Int constructor called " << std::endl;
}

Fixed::Fixed(float num) {
	_integer = roundf(num * (1 << _st_const_int));
	std::cout << "Float constructor called " << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
	_integer = other._integer;
}

Fixed& Fixed::operator = (const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	_integer = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	_integer = raw;
}
