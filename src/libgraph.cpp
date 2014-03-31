#include "libgraph.hpp"

static int midx, midy;

void init_graph(){
	int gdriver = DETECT; int gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	
	printf("%d %d\n", midx, midy);
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

void draw_ellipse(int xc, int yc, int rx,int ry, int color){
	int x=0,y=ry;
	int p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
	while((2*x*ry*ry)<(2*y*rx*rx)){
		paintpix(xc+x,yc+y,color);
		paintpix(xc-x,yc-y,color);
		paintpix(xc+x,yc-y,color);
		paintpix(xc-x,yc+y,color);
	   
		if(p<0){
		   x=x+1;
		   p=p+(2*ry*ry*x)+(ry*ry);
		} else {
		   x=x+1;
		   y=y-1;
		   p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
		}
	}
		p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;
    
	while(y>=0){
		paintpix(xc+x,yc+y,color);
		paintpix(xc-x,yc-y,color);
		paintpix(xc+x,yc-y,color);
		paintpix(xc-x,yc+y,color);

		if(p>0){
		   y=y-1;
		   p=p-(2*rx*rx*y)+(rx*rx);
		} else {
		   y=y-1;
		   x=x+1;
		   p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
	    }
	}
}

void fill (int x, int y, int fill_color, int boundary_color)
{
	int current;
	current = getpixel(x, y);
	
	if ((current != boundary_color) &&  (current != fill_color)){
		setcolor(fill_color);
		paintpix(x, y, fill_color);
		
		boundaryFill4 (x+1, y, fill_color, boundary_color); //right
		boundaryFill4 (x-1,  y, fill_color, boundary_color); //left
		boundaryFill4 (x, y-1, fill_color, boundary_color) ; //up
		boundaryFill4 (x, y+1, fill_color, boundary_color); //down
	}
}