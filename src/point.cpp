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

void Point::set(float x, float y){
	this->x = x; this->y = y;
}

void Point::applyTransform(matrix_t& m){
	matrix_t res;
	float pdata[3][1]; pdata[0][0] = x; pdata[1][0] = y; pdata[2][0] = 1;
	
	res = mmultiply(m, (float*) pdata, 1);
	x = res.data[0][0]; y = res.data[1][0];
}

void Point::applyTransform(Transform trans){
	applyTransform(trans.mat);
}

void draw_line(const Point& p1, const Point& p2, int color){
	draw_line(p1.x, p1.y, p2.x, p2.y, color);
}