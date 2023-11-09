#include "Fixed.h"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	_integer = raw;
}
