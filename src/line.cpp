#include "line.hpp"

Line::Line(){}
Line::Line(int x1, int y1, int x2, int y2) : p1(x1,y1), p2(x2, y2){}

void Line::applyTransform(Transform& trans){
	p1.applyTransform(trans);
	p2.applyTransform(trans);
}

void Line::draw(int color){
	draw_line(p1, p2, color);
}