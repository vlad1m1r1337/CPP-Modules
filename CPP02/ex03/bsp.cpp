#include "Point.h"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	(void)c;
	(void)point;
	Fixed ABxAP = (b.getterX() - a.getterX()) * (point.getterY() - a.getterY()) - (b.getterY() - a.getterY()) * (point.getterX() - a.getterX());
	Fixed BCxBP = (c.getterX() - b.getterX()) * (point.getterY() - b.getterY()) - (c.getterY() - b.getterY()) * (point.getterX() - b.getterX());
	Fixed CAxCP = (a.getterX() - c.getterX()) * (point.getterY() - c.getterY()) - (a.getterY() - c.getterY()) * (point.getterX() - c.getterX());

//	std::cout << "ABxAP = " << ABxAP << std::endl;
//	std::cout << "BCxBP = " << BCxBP << std::endl;
//	std::cout << "CAxCP = " << CAxCP << std::endl;

	if (ABxAP > 0 && BCxBP > 0 & CAxCP > 0) {
		return true;
	}
	else if (ABxAP < 0 && BCxBP < 0 & CAxCP < 0)
	{
		return true;
	}
	else {
		return false;
	}
}
