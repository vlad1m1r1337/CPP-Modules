#include "Fixed.h"
#include "Point.h"
#include "bsp.cpp"

int main( void ) {
	//small triangle in
//	Point const a(0, 0);
//	Point const b(0.5f, 1);
//	Point const c(1, 0);
//	Point const p(0.5f, 1);

	//norm triangle out
//	Point const a(7, 7);
//	Point const b(11, 1);
//	Point const c(2, 2);
//	Point const p(7, 7.1f);

	//norm triangle vertex
	Point const a(7, 7);
	Point const b(11, 1);
	Point const c(2, 2);
	Point const p(2, 2);

	bool  inside = bsp(a, b, c, p);
	std::cout << inside << std::endl;
	return 0;
}
