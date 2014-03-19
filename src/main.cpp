#include "libgraph.hpp"
#include "quad.hpp"


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
	
	draw_ellipse(10, 10, 30, 80, 255);
	
	Quad q (-100, -100, -50, -50);
	Transform t = createScale(0.01, 0.01);
	
	q.applyTransform(t);
	
	t = createScale(1.1, 1.1);
	
	draw_line(0, 0, -250, -240, 255);
	draw_line(0, 0, 250, -240, 255);
	
	for(int i = 0; i < 75; i++){
		//cleardevice();
		
		q.draw(255);
		
		q.applyTransform(t);
		
		delay(50);
	}
	
	
	
	getch();
	return 0;

}