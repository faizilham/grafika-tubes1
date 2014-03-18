#include "point.hpp"

Point::Point(){
	x = 0; y = 0;
}

Point::Point(float x, float y){
	this->x = x; this->y = y;
}

Point operator+ (const Point& p1, const Point& p2){
	Point p(p1.x + p2.x, p1.y + p2.y);
	return p;
}

Point operator* (const Point& p, float factor){
	Point q(p.x * factor, p.y * factor);
	return q;
}

Point operator* (float factor, const Point& p){
	return p * factor;
}

void Point::draw(int color){
	paintpix(x, y, color);
}