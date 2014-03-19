#ifndef POINT_HPP
#define POINT_HPP

#include "libgraph.hpp"
#include "trans.hpp"

class Point{
	public:
		float x, y;
		
		Point();
		Point(float x, float y);
		friend Point operator+ (const Point& p1, const Point& p2);
		friend Point operator* (const Point& p, float factor);
		friend Point operator* (float factor, const Point& p);
		
		void draw(int color);
		void set(float x, float y);
		
		void applyTransform(matrix_t& m);
		void applyTransform(Transform trans);
};

void draw_line(const Point& p1, const Point& p2, int color);

#endif