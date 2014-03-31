#ifndef CAR_HPP
#define CAR_HPP

#include "shapes.hpp"
#define CAR_LENGTH 40
#define STARTX -1*(CAR_LENGTH)
#define STARTY -225

enum CarState {LEFT, CENTER, RIGHT};
class Car{
	private:
		Line depan[3];
		Quad body;
		CarState state;
		Transform moveLeft, moveRight;
		
	public:
		Car();
		int getLane();
		Point getFrontPoint();
		Point getBackPoint();
		void update(char c);
		void draw();
};
#endif