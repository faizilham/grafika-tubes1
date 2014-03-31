#ifndef TEXT_COUNTDOWN_HPP
#define TEXT_COUNTDOWN_HPP

#include "libgraph.hpp"

class TextCountdown{
	public:
		//initial counter number
		int counter;
		int tenth;
		//position
		int x;
		int y;
		//style
		int style;
		int size;
		int color;
		
		//ctor
		TextCountdown(int startAt, int _x, int _y);
		TextCountdown(int startAt,int _x,int _y,int _style, int _size, int _color);
		
		//function member
		void update();
};

#endif