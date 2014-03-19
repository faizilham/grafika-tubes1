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
		
	Quad q (-100, -100, -50, -50);
	Transform t = createScale(0.01, 0.01);
	
	q.applyTransform(t);
	
	t = createScale(1.7, 1.7);
	
	for(int i = 0; i < 10; i++){
		cleardevice();
		
		draw_line(0, 0, -250, -240, 255);
		draw_line(0, 0, 250, -240, 255);
		
		q.draw(255);
		
		q.applyTransform(t);
		
		delay(500);
	}
	
	
	
	getch();
	return 0;

}