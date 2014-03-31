#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "libgraph.hpp"
#include "trans.hpp"
#include <vector>
using namespace std;

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

class Circle{
	public:
		Point center;
		float radx,rady;
		Circle();
		Circle(Point p, float rx, float ry);

		void applyTransform(matrix_t& m);
		void applyTransform(Transform& trans);
		void draw(int color);
};

class Line{
	public:
	Point p1, p2;
	Line();
	Line(int x1, int y1, int x2, int y2);
	Line(Point _p1, Point _p2);

	void applyTransform(Transform& trans);
	void draw(int color);
};

class Quad{	
	public:
		vector<Point> corner;
		Point center;
		Quad();
		Quad(int x1, int y1, int x2, int y2);
		
		void draw(int color); // non fill
		Point& operator[] (int i);
		
		void applyTransform(Transform& trans);
		void selfRotate(int deg);
};

Quad createRect(int x1, int y1, int x2, int y2);

class Polygon{
	public:
		vector<Point> corner;
		Point center;
		Polygon();
		Polygon(vector<Point> corn,Point center);
		Point& operator[] (int i);
		void draw(int color);
		void setCorner(vector<Point> corn);
		void setCenter(Point ctr);
		void applyTransform(Transform& trans);

};

#endif