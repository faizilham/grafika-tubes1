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
	
	//buat gerak
	moveRight = createTranslation(SPEED, 0);
	moveLeft = createTranslation(-1*SPEED, 0);
}

void Car::update(char c){
	if(c == 75){
		for(int i=0;i<3;i++)
			depan[i].applyTransform(moveLeft);
		body.applyTransform(moveLeft);
	} else if(c == 77){
		for(int i=0;i<3;i++)
			depan[i].applyTransform(moveRight);
		body.applyTransform(moveRight);
	}
}

void Car::draw(){
	for(int i=0;i<3;i++)
		depan[i].draw(255);
	body.draw(255);
}