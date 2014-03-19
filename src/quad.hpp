#ifndef QUAD_HPP
#define QUAD_HPP

#include "point.hpp"

// quadrilateral class

class Quad{	
	public:
		Point corner[4], center;
		Quad();
		Quad(int x1, int y1, int x2, int y2);
		
		void draw(int color); // non fill
		Point& operator[] (int i);
		
		void applyTransform(Transform& trans);
		void selfRotate(int deg);
};

Quad createRect(int x1, int y1, int x2, int y2);

#endif

