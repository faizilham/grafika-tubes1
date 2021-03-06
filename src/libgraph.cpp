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
	int cartesian_x = midx + x;
	int cartesian_y = midy - y;
	int current;
	current = getpixel(cartesian_x, cartesian_y);

	if ((current != boundary_color) &&  (current != fill_color)){
		setcolor(fill_color);
		paintpix(x, y, fill_color);

		fill (x + 1, y, fill_color, boundary_color); //right
		fill (x - 1,  y, fill_color, boundary_color); //left
		fill (x, y - 1, fill_color, boundary_color) ; //up
		fill (x, y + 1, fill_color, boundary_color); //down
	}
}

bool isExtremePoint(int x, int y){
	bool result;
	int cartesian_x = midx + x;
	int cartesian_y = midy - y;
	int boundary_color = getpixel(cartesian_x, cartesian_y);
	
	//neighbouring pixels
	int left_color = getpixel(cartesian_x-1, cartesian_y);
	int right_color = getpixel(cartesian_x+1, cartesian_y);
	int leftbottom_color = getpixel(cartesian_x-1, cartesian_y-1);
	int rightbottom_color = getpixel(cartesian_x+1, cartesian_y-1);
	int bottom_color = getpixel(cartesian_x, cartesian_y-1);
	
	if((left_color != boundary_color)
		&& (right_color != boundary_color)
		&& (leftbottom_color != boundary_color)
		&& (rightbottom_color != boundary_color)
		&& (bottom_color != boundary_color)){
			result = true;
	}
	else{
		result = false;
	}
	
	return result;
}

void fill_polygon (int xmin, int ymin, int xmax, int ymax, int fill_color, int boundary_color){
//trying to use scan line algorithm
//horizontal scan line
	int curr_x, curr_color;
	
	//scan line
	for(int y = ymin+1; y < ymax; y++){
		curr_x = xmin;
		bool status = false;
		//go to the leftmost edge
		curr_color = getpixel(midx + curr_x,midy - y);
		while((curr_color != boundary_color) && (curr_x < xmax)){
			curr_x++;
			curr_color = getpixel(midx + curr_x,midy - y);
		}
		//found the leftmost edge
		if(curr_color == boundary_color){
			while(curr_x < xmax){
				curr_color = getpixel(midx + curr_x,midy - y);
				//if curr_x meets the boundary edge
				if(curr_color == boundary_color){
					if(isExtremePoint(curr_x,y) == false){
						status = !status;
					}
				}
				if(status == true){
					//if curr_x is inside the polygon
					if ((curr_color != boundary_color) &&  (curr_color != fill_color)){
						setcolor (fill_color);
						paintpix(curr_x, y, fill_color);
					}
				}
				curr_x++;
			}
		}
	}	
}




