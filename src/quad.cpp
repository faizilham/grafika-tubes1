#include "quad.hpp"

Point corner[4], center;
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
