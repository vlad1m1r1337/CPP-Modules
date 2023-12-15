#ifndef CPPMODULESPROJECT_POINT_H
#define CPPMODULESPROJECT_POINT_H

# include "Fixed.h"

class Point {
private:
	Fixed x;
	Fixed y;
public:
	Point(int x, int y);
	Point(int x, float y);
	Point(float x, int y);
	Point(float x, float y);
	Fixed getterX() const;
	Fixed getterY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
