#include "road.hpp"
#include "obstacle_manager.hpp"
#include "car.hpp"
#include "result.hpp"
#include "text_countdown.hpp"
#include <algorithm>

Point b1,b2,b3,b4;//bounds

bool getch_async(char& c){
	// non-blocking getch
	
	if (kbhit()){
		c = getch();
		if(c == 0){ //Handle arrow key
			c = getch();
			//printf("Char: %d\n", c);
		}
		
		return true;
	}else{
		return false;
	}
}

//Outcode format: LRBT
int getOutcode(int x, int y){//, int leftx, int rightx, int bottomy, int topy){
	int outcode = 0;
	if(x < b1.x){
		outcode += 8;
	}
	if(x > b4.x){
		outcode += 4;
	}
	if(y < b1.y){
		outcode += 2;
	}
	if(y > b2.y){
		outcode += 1;
	}
	return outcode;
}

//pake cohen-sutherland line clipping algorithm
void draw_line_b(int x1, int y1, int x2, int y2, int color){
	int o1 = getOutcode(x1, y1);
	int o2 = getOutcode(x2, y2);
		
	//printf("Outcodes: %d %d\n", o1, o2);
	
	if((o1 | o2) == 0){
		//trivial accepted
		//printf("trivial accepted\n");
		draw_line(x1, y1, x2, y2, color);
	} else if((o1 & o2) >= 1){
		//printf("trivial rejected\n");
		//trivial rejected
		//dont draw
	} else {
		int count = 0;
		while(o1 > 0 || o2 > 0){
			//printf("----\n");
			
			
			
			if(o1 == 0){
				//didalam, berarti satunya pasti diluar
				//pastikan (x1,y1) yg berada diluar
				swap(x1,x2);
				swap(y1,y2);
				swap(o1,o2);
			}
			
			//printf("Outcodes [%d]: %d %d\n", count, o1, o2);
			//printf("Coord [%d]: (%d %d) (%d %d)\n", count, x1,y1,x2,y2);
			//printf("Yg dibenerin poin: %d %d\n", x1,y1);
			
			count++;
			if(count == 3){
				break;
			}
			int tmp = o1;
			int it = 0;
			while(tmp > 0){
				if(tmp % 2 == 1){
					//printf("it: %d\n", it);
					if(it == 0){//TOP
						int newy = b2.y;
						int newx = round(((x2 - x1)/((float)(y2 - y1)))*(newy - y1) + x1);
						
						x1 = newx;
						y1 = newy;
					} else if(it == 1){//BOTTOM
						int newy = b1.y;
						//printf("calc: %d %d %d %d\n",(x2 - x1), (y2 - y1), (newy - y1), x1);
						int newx = round(((x2 - x1)/((float)(y2 - y1)))*(newy - y1) + x1);
						
						x1 = newx;
						y1 = newy;
					} else if(it == 2){//RIGHT
						int newx = b4.x;
						int newy = round(((y2 - y1)/((float)(x2 - x1)))*(newx - x1) + y1);
						
						x1 = newx;
						y1 = newy;
					} else if(it == 3){//LEFT
						int newx = b1.x;
						int newy = round(((y2 - y1)/((float)(x2 - x1)))*(newx - x1) + y1);
						//printf("newy: %d\n",newy);
						
						
						x1 = newx;
						y1 = newy;
					}
				}
				it++;
				tmp /= 2;
			}
			
			//recompute outcodes
			o1 = getOutcode(x1, y1);
			o2 = getOutcode(x2, y2);
		}
		
		//printf("Coord: (%d %d) (%d %d)\n", x1,y1,x2,y2);
		
		//Apabila setelah dilakukan transformasi berada didalam clipping...
		if((o1 | o2) == 0){
			draw_line(x1, y1, x2, y2, color);
		}
	}
}

void draw_polygon_b(vector<Point> corn, int color){
	int l = corn.size();
	for (int i = 0; i < l-1; i++){
		draw_line_b(corn[i].x, corn[i].y, corn[i+1].x, corn[i+1].y, color);
	}
	draw_line_b(corn[l-1].x, corn[l-1].y, corn[0].x, corn[0].y, color);
}

void magnifyClip(float factor){
	b1 = b1 * factor;
	b2 = b2 * factor;
	b3 = b3 * factor;
	b4 = b4 * factor;
}

int main(){
	init_graph();
	
	b1.x = -100; b1.y = -100;
	b2.x = -100; b2.y = 100;
	b3.x = 100; b3.y = 100;
	b4.x = 100; b4.y = -100;
	
	bool magnified = false;
	
	char c = 0;
	
	// the game loop
	bool drawn = false;
	
	//segitiga
	vector<Point> poly;
	poly.push_back(Point(-50, 50));
	poly.push_back(Point(-60, 140));
	poly.push_back(Point(-200, 60));
	
	while (c != 'q'){
		cleardevice();
	
		//boundary
		draw_line(b1, b2, YELLOW);
		draw_line(b2, b3, YELLOW);
		draw_line(b3, b4, YELLOW);
		draw_line(b1, b4, YELLOW);		 
		
		//draw_line(-60, 140, -250, 60, WHITE);
		draw_line_b(0, 0, 50, 50, WHITE);
		draw_line_b(0, -125, 125, 0, WHITE);
		draw_line_b(-150, -150, 150, -150, WHITE);
		//if(!drawn){
		draw_polygon_b(poly, WHITE);
			//drawn = true;
		//}
		//draw_line(-100, -225, 125, 0, WHITE);
		c = 0;
		delay(100);
		getch_async(c);
		if(c == 'm'){
			if(magnified){
				magnifyClip(0.5f);
			} else{
				magnifyClip(2);
			}
			magnified ^= 1;
		}
	}
	
	
	return 0;

}