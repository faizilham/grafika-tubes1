#ifndef CAR_HPP
#define CAR_HPP

#include "shapes.hpp"
#define CAR_LENGTH 50
#define STARTX -1*(CAR_LENGTH/2)
#define STARTY -225
#define SPEED 15

class Car{
	private:
		Line depan[3];
		Quad body;
		Transform moveRight, moveLeft;
		
	public:
		Car();
		
		void update(char c);
		void draw();
};

#endif