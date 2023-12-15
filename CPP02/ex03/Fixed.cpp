#include "Fixed.h"

const int Fixed::_st_const_int = 8;

float Fixed::toFloat( void ) const {
	return static_cast<float>(_integer) / (1 << _st_const_int);
}

int Fixed::toInt( void ) const {
	return _integer >> _st_const_int;
}

Fixed::Fixed() {
	_integer = 0;
}

Fixed::Fixed(int num) {
    _integer = num << _st_const_int;
}

Fixed::Fixed(float num) {
	_integer = roundf(num * (1 << _st_const_int));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& other) {
	_integer = other._integer;
}

Fixed& Fixed::operator = (const Fixed &other) {
	_integer = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	_integer = raw;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj)
{
	std::cout << obj.toFloat();
	return ostream;
}

bool Fixed::operator==(const Fixed& obj) const {
	return _integer == obj._integer;
}

bool Fixed::operator!=(const Fixed& obj) const {
	return _integer != obj._integer;
}

bool Fixed::operator<(const Fixed& obj) const {
	return _integer < obj._integer;
}

bool Fixed::operator<=(const Fixed& obj) const {
	return _integer <= obj._integer;
}

bool Fixed::operator>(const Fixed& obj) const {

	return _integer > obj._integer;
}

bool Fixed::operator>=(const Fixed& obj) const {
	return _integer >= obj._integer;
}

Fixed operator + (const Fixed& c1, const Fixed& c2)
{
	return Fixed(c1.toFloat() + c2.toFloat());
}

Fixed operator - (const Fixed& c1, const Fixed& c2)
{
	return Fixed(c1.toFloat() - c2.toFloat());
}

Fixed operator * (const Fixed& c1, const Fixed& c2)
{
	return Fixed(c1.toFloat() * c2.toFloat());
}

Fixed operator / (const Fixed& c1, const Fixed& c2)
{
	return Fixed(c1.toFloat() / c2.toFloat());
}

Fixed& Fixed::operator++ (void)
{
	_integer++;
	return *this;
}

Fixed& Fixed::operator-- (void)
{
	_integer--;
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed copy(*this);
	--(*this);
	return copy;
}

Fixed Fixed::operator++ (int)
{
	Fixed copy (*this);
	++(*this);
	return copy;
}

Fixed Fixed::max(const Fixed& c1, const Fixed &c2) {
	return c1 > c2 ? c1 : c2;
}

Fixed Fixed::min(const Fixed& c1, const Fixed &c2) {
	return c1 < c2 ? c1 : c2;
}
