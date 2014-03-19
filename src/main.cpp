#include "libgraph.hpp"
#include "point.hpp"


void print(Transform t){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%.2f ", t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){

	init_graph();
	
	Point p1(100, 100); Point p2(150, 100);
	Transform T, R, T1;
	T = createTranslation(-100, -100);
	T1 = createTranslation(100, 100);
	R = createRotation(4);
	
	//Transform r1 = R * T;
	Transform r2 = T1 * R * T;
	
	
	for (int i = 0; i < 90; i++){
		draw_line(p1.x, p1.y, p2.x, p2.y, 255);
		
		p1.applyTransform(r2);
		p2.applyTransform(r2);
		
		delay(30);
	}
	
	if (!kbhit()){
		printf("no key pressed\n");
	}
	
	getch();
	return 0;

}