#include "Fixed.h"

int main() {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	a.setRawBits(0);
	a.setRawBits(0);
	a.setRawBits(0);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}