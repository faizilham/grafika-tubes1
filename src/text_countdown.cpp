#include "text_countdown.hpp"
static int midx = getmaxx()/2;
static int midy = getmaxy()/2;


//ctor
TextCountdown::TextCountdown(int startAt, int _x, int _y){
	counter = startAt;
	tenth = 10;
	x = _x;
	y = _y;
	style = 7;
	size = 60;
	color = YELLOW;
}
TextCountdown::TextCountdown(int startAt,int _x,int _y,int _style, int _size, int _color){
	counter = startAt;
	tenth = 10;
	x = _x;
	y = _y;
	style = _style;
	size = _size;
	color = _color;
}

//function member
void TextCountdown::update(){
	//assume we are using 100ms delay
	if(counter > 0){
		tenth--;
		if(tenth == 0){
			counter--;
			tenth = 10;
		}
	}
}