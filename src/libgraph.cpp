#include "libgraph.hpp"

void init_graph(){
	int gdriver = DETECT; int gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	midx=getmaxx()/2;
	midy=getmaxy()/2;
}

void paintpix(int x, int y, int color){
	//putpixel(midx + x, midy - y, color); // put pixel with translation & rounding
	putpixel(midx + x, midy - y, color);
}

void draw_line(int x1, int y1, int x2, int y2, int color){
	// using bresenham algorithm

	int error = 0, x, y, dx, dy, c1, c2, c3;
	
	if (abs(x1 - x2) > abs(y1 - y2)){ // low slope, |m| < 1
		int xstart, xfinish;
	
		// calculate start-end x
		if (x1 < x2){
			xstart = x1; xfinish = x2;
			dx = x2 - x1; dy = y2 - y1; y = y1;
		}else{
			xstart = x2; xfinish = x1;
			dx = x1 - x2; dy = y1 - y2; y = y2;
		}
		
		// calculate constants depends on positive of negative gradient
		if (dy > 0){
			c1 = 2; c2 = 1; c3 = dy - dx;
		}else{
			c1 = -2; c2 = -1; c3 = dy + dx;
		}
		
		for (x = xstart; x <= xfinish; x++){
			paintpix(x, y, color);
			
			// calculate next error and next y
			if (c1*(error + dy) < dx){
				error += dy;
			}else{
				y+=c2; error += c3;
			}
		}
	
	}else{ // high slope, |m| >= 1
		int ystart, yfinish;
	
		// calculate start-end y
		if (y1 < y2){
			ystart = y1; yfinish = y2;
			dy = y2 - y1; dx = x2 - x1; x = x1;
		}else{
			ystart = y2; yfinish = y1;
			dy = y1 - y2; dx = x1 - x2; x = x2;
		}
		
		// calculate constants depends on positive of negative gradient
		if (dx > 0){
			c1 = 2; c2 = 1; c3 = dx - dy;
		}else{
			c1 = -2; c2 = -1; c3 = dx + dy;
		}
		
		for (y = ystart; y <= yfinish; y++){
			paintpix(x, y, color);
			
			// calculate next error and next x
			if (c1*(error + dx) < dy){
				error += dx;
			}else{
				x+=c2; error += c3;
			}
		}
	}
}

