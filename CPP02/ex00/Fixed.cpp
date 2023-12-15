#include "Fixed.h"

const int Fixed::_st_const_int = 8;

Fixed::Fixed() {
    _integer = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	_integer = other._integer;
	std::cout << "Copy constructor called" << std::endl;
}

    Fixed& Fixed::operator = (const Fixed &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        _integer = other.getRawBits();
        return *this;
    }

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	_integer = raw;
}
