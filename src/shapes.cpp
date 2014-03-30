#include "shapes.hpp"

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

Line::Line(){}
Line::Line(int x1, int y1, int x2, int y2) : p1(x1,y1), p2(x2, y2){}

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
	corner[0].set(x1,y1);
	corner[1].set(x2,y1);
	corner[2].set(x2,y2);
	corner[3].set(x1,y2);
	
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
