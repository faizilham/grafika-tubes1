#ifndef LINE_HPP
#define LINE_HPP

#include "point.hpp"

class Line{
	public:
	Point p1, p2;
	Line();
	Line(int x1, int y1, int x2, int y2);
	
	void applyTransform(Transform& trans);
	void draw(int color);
};

#endif