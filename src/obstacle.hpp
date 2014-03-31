#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "shapes.hpp"
#include "trans.hpp"


class Obstacle{
	public:
		int frame, lane;
		Point p;
		Obstacle() : frame (0), lane(0) {}
		virtual ~Obstacle(){}
		
		virtual void applyTransform(Transform& trans){}
		virtual void reset(){}
		virtual void setLane(int lane){} //0 left, 1 middle, 2 right
		virtual Point getFrontPoint(){}
		virtual void draw(){}
};

#endif
