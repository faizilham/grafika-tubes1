#include "libgraph.hpp"
#include "point.hpp"


int main(){

	init_graph();
	
	Point p1(0, 0); Point p2(50, 0);
	Transform rot = createRotation(4);
	Transform t2 =	createTranslation(60, 0) * createScale(0.5, 0.5);
	
	for (int i = 0; i < 180; i++){
		draw_line(p1.x, p1.y, p2.x, p2.y, 255);
		
		p1.applyTransform(rot);
		p2.applyTransform(rot);
		
		if (i == 89){
			p1.applyTransform(t2);
			p2.applyTransform(t2);
		}
		
		delay(30);
	}
	readkey();
	return 0;

}