#include "road.hpp"

Road::Road(){
	roadmark[0] = Line(0, -180, 0, -240);
	Transform s = createScale(0.5, 0.5);
	
	for (int i = 1; i < ROAD_MARK_NUM; i++){
		roadmark[i] = roadmark[i-1];
		roadmark[i].applyTransform(s);
	}
	
	move = createScale(2.5, 2.5);
	
	int factor = 1 << (ROAD_MARK_NUM - 1);
	
	reset = createScale(1.0/factor, 1.0/factor);
}
	
void Road::update(){	
	for (int i = 0; i < ROAD_MARK_NUM; i++){
		roadmark[i].applyTransform(move);
		if (roadmark[i].p1.y < -240)
			roadmark[i].applyTransform(reset);
	}
}

void Road::draw(){
	draw_line(-320, 0, 320, 0, WHITE);
	draw_line(0, 0, -270, -240, WHITE); // left
	draw_line(0, 0, 270, -240, WHITE); // right
	
	for (int i = 0; i < ROAD_MARK_NUM; i++){
		roadmark[i].draw(WHITE);
	}
}