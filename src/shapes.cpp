#include "shapes.hpp"
#include <cstdio>

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


Circle::Circle(){}
Circle::Circle(Point p, float rx, float ry){
	center = p;
	radx = rx;
	rady = ry;
}

void Circle::applyTransform(matrix_t& m){
	matrix_t res;
	float pdata[3][1]; pdata[0][0] = center.x; pdata[1][0] = center.y; pdata[2][0] = 1;
	
	res = mmultiply(m, (float*) pdata, 1);
	center.x = res.data[0][0]; center.y = res.data[1][0];
	radx*=1.1;
	rady*=1.1;
}

void Circle::applyTransform(Transform& trans){
	applyTransform(trans.mat);
}

void Circle::draw(int color){
	draw_ellipse(center.x, center.y, radx, rady, color);
}


Line::Line(){}
Line::Line(int x1, int y1, int x2, int y2) : p1(x1,y1), p2(x2, y2){}
Line::Line(Point _p1, Point _p2) : p1(_p1.x, _p1.y), p2(_p2.x, _p2.y){
}
void Line::applyTransform(Transform& trans){
	p1.applyTransform(trans);
	p2.applyTransform(trans);
}

void Line::draw(int color){
	draw_line(p1, p2, color);
}

Quad::Quad(){}

Quad::Quad(int x1, int y1, int x2, int y2){
	// rectangle
	Point p1(x1,y1);
	Point p2(x2,y1);
	Point p3(x2,y2);
	Point p4(x1,y2);
	corner.push_back(p1);
	corner.push_back(p2);
	corner.push_back(p3);
	corner.push_back(p4);
	
	center.set((x2+x1)/2, (y2+y1)/2);
}
		

void Quad::draw(int color){
	for (int i = 0; i < 3; i++){
		draw_line(corner[i], corner[i+1], color);
	}
	
	draw_line(corner[3], corner[0], color);
}

void Quad::applyTransform(Transform& trans){
	for (int i = 0; i < 4; i++){
		corner[i].applyTransform(trans);
	}
	
	center.applyTransform(trans);
}

void Quad::selfRotate(int deg){
	Transform t = createTranslation(center.x, center.y) * createRotation(deg) * createTranslation(-center.x, -center.y);
	
	for(int i = 0; i < 4; i++){
		corner[i].applyTransform(t);
	}
}

Point& Quad::operator[] (int i){
	return corner[i];
}

Polygon::Polygon(){

}

Polygon::Polygon(vector<Point> corn, Point ctr){
	corner = corn;
	center = center;
}

void Polygon::applyTransform(Transform& trans){
	int l = corner.size();
	for (int i = 0; i < l; i++){
		corner[i].applyTransform(trans);
	}
	
	center.applyTransform(trans);
}

void Polygon::draw(int color){
	int l = corner.size();
	for (int i = 0; i < l-1; i++){
		draw_line(corner[i], corner[i+1], color);
	}
	draw_line(corner[l-1], corner[0], color);
}

void Polygon::setCorner(vector<Point> corn){
	corner = corn;
}

void Polygon::setCenter(Point ctr){
	center = ctr;
}

Point& Polygon::operator[] (int i){
	return corner[i];
}

