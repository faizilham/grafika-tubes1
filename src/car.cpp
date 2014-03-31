#include "car.hpp"

Car::Car(){
	//Car shape
	/*   P3-------P4
	     /         \
	    /           \
	   P1-----------P2
	   |    QUAD     |
	   ---------------
	*/
	
	state = CENTER;
	
	body = Quad(STARTX, STARTY, STARTX + CAR_LENGTH*2, STARTY + CAR_LENGTH);
	
	Point P1,P2,P3,P4,P5,P6;
	P1 = Point(STARTX, STARTY + CAR_LENGTH);
	P2 = Point(STARTX + 2*CAR_LENGTH, STARTY + CAR_LENGTH);
	P3 = P1;
	P3.applyTransform(createTranslation(CAR_LENGTH/2, CAR_LENGTH));
	P4 = P2;
	P4.applyTransform(createTranslation(-CAR_LENGTH/2, CAR_LENGTH));
	
	depan[0] = Line(P1, P3);
	depan[1] = Line(P3, P4);
	depan[2] = Line(P2, P4);
	moveLeft = createTranslation(-120,0);
	moveRight = createTranslation(120,0);
}

void Car::update(char c){
	if(c == 75){
		//printf("State: %d\nPencet kanan.\n", state);
		if(state == CENTER || state == LEFT){
			body.applyTransform(moveLeft);
			for(int i=0;i<3;i++){
				depan[i].applyTransform(moveLeft);
			}
		}
		if(state == CENTER)
			state = RIGHT;
		else if(state == LEFT)
			state = CENTER;
	} else if(c == 77){
		//printf("State: %d\nPencet kanan.\n", state);
		if(state == CENTER || state == RIGHT){
			body.applyTransform(moveRight);
			for(int i=0;i<3;i++){
				depan[i].applyTransform(moveRight);
			}
		}
		if(state == CENTER)
			state = LEFT;
		else if(state == RIGHT)
			state = CENTER;
	}
}

void Car::draw(){
	for(int i=0;i<3;i++)
		depan[i].draw(255);
	body.draw(YELLOW);
	
	fill_polygon(body.corner[0].x, body.corner[0].y, body.corner[2].x, body.corner[2].y,RED,YELLOW);
}