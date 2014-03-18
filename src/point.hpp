#ifndef POINT_H
#define POINT_H

#include "libgraph.hpp"

class Point{
	public:
		float x, y;
		
		Point();
		Point(float x, float y);
		friend Point operator+ (const Point& p1, const Point& p2);
		friend Point operator* (const Point& p, float factor);
		friend Point operator* (float factor, const Point& p);
		
		void draw(int color);
};

#endif