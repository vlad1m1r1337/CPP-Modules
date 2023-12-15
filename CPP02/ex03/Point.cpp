#include "Point.h"

Point::Point(int x, int y) : x(x), y(y){
}

Point::Point(float x, int y) : x(x), y(y){
}

Point::Point(int x, float y) : x(x), y(y){
}

Point::Point(float x, float y) : x(x), y(y){
}

Fixed Point::getterX()  const{
	return x;
}

Fixed Point::getterY()  const{
	return y;
}
