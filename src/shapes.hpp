#ifndef SHAPES_HPP
#define SHAPES_HPP

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

class Line{
	public:
	Point p1, p2;
	Line();
	Line(int x1, int y1, int x2, int y2);
	
	void applyTransform(Transform& trans);
	void draw(int color);
};

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