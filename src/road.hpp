#ifndef ROAD_HPP
#define ROAD_HPP

#include "shapes.hpp"

#define ROAD_MARK_NUM 8

class Road{
	private:
		Transform move, reset;
		Line roadmark[ROAD_MARK_NUM];
	public:
		Road();
	
		void update();
		void draw();
};

#endif